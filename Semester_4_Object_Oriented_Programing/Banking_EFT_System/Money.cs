using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace _2017280030_OOP_Final
{
    internal abstract class Money:IFileOperation
    {
        internal static Exchange<string, double> Exchange = new Exchange<string, double>();
        internal string Iban { get; set; }
        protected double Currency { get; set; }
        protected string Type { get; set; }
        internal string SendMoneyByEft(double willSend)
        {
            if (willSend<=Currency)
            {
                this.Currency -= willSend;
                this.Update();
                return this.Type;
            }
            return null;
            
        }
        internal string GetInfo()
        {
            return GetIbanInfo() + "\n           " + Currency.ToString(".00")+Type;
        }
        internal string GetIbanInfo()
        {
            return Iban;
        }
        internal abstract void TakeMoneyByEft(double willSend, string Type);
        public void Read()
        {
            FileStream fileStream;
            StreamReader streamReader;
            try
            {
                fileStream = new FileStream(@"c:\\final\\client.txt", FileMode.Open, FileAccess.Read);
                streamReader = new StreamReader(fileStream);
                string line = streamReader.ReadLine();
                if (line == null)
                {
                    streamReader.Close();
                    fileStream.Close();
                    new Error("Client File is Empty.");
                }
                while (line != null)
                {
                    string[] lines = line.Split(',');
                    if (String.Compare(lines[3], "TL") == 0)
                    {
                        BankAccount client = AccountHolders.FindClient(lines[0], "Account Number");
                        client.SetAccounts(new Tl(lines[1], Convert.ToDouble(lines[2])));
                    }
                    else if (String.Compare(lines[3], "EURO") == 0)
                    {
                        BankAccount client = AccountHolders.FindClient(lines[0], "Account Number");
                        client.SetAccounts(new Euro(lines[1], Convert.ToDouble(lines[2])));
                    }
                    else if (String.Compare(lines[3], "USD") == 0)
                    {
                        BankAccount client = AccountHolders.FindClient(lines[0], "Account Number");
                        client.SetAccounts(new Usd(lines[1], Convert.ToDouble(lines[2])));
                    }
                    line = streamReader.ReadLine();
                }
                streamReader.Close();
                fileStream.Close();
            }catch(Exception exception)
            {
                FileOperations.CreateDefaultClient("force");
                this.Read();
                MessageBox.Show(exception+ "All Currency forget!", "Problem", MessageBoxButtons.OK);
            }
        }
        public bool Check(string key)//double check
        {
            bool correct=false;
            if (this.Currency < Convert.ToDouble(key))
                return false;
            FileStream fileStream=null;
            StreamReader streamReader=null;
            try
            {
                if (!File.Exists(@"c:\\final\\client.txt"))
                {
                    new Error("File not found!");
                }
                fileStream = new FileStream(@"c:\\final\\client.txt", FileMode.Open, FileAccess.Read);
                streamReader = new StreamReader(fileStream);
                string line = streamReader.ReadLine();
                if (line == null)
                {
                    new Error("Auth File is Empty.");
                    streamReader.Close();
                    fileStream.Close();
                }
                while (line != null)
                {
                    string[] lines = line.Split(',');
                    if (String.Compare(lines[1],this.Iban) == 0)
                    {
                        if (this.Currency==Convert.ToDouble(lines[2]))
                        {
                            correct=true;
                        }
                    }
                    line = streamReader.ReadLine();

                }
                streamReader.Close();
                fileStream.Close();
            }
            #pragma warning disable CS0168
            catch (Exception exception)
            {
                #pragma warning restore CS0168
                if (streamReader != null)
                    streamReader.Close();
                if(fileStream!=null)
                    fileStream.Close();
                throw new Error("Dedect Problem For File Operation That Process is invalid.");
            }
            return correct;
        }
        public void Update()
        {
            FileStream fileStream=null;
            StreamReader streamReader=null;
            StreamWriter streamWrite=null;
            try
            {
                fileStream = new FileStream(@"c:\\final\\client.txt", FileMode.Open, FileAccess.Read);

                streamReader = new StreamReader(fileStream);
                string[] lines = streamReader.ReadToEnd().Split('\n');
                streamReader.Close();
                if (lines == null)
                {
                    new Error("Client File is Empty.");
                    streamReader.Close();
                    fileStream.Close();
                }
                fileStream = new FileStream(@"c:\\final\\client.txt", FileMode.Create, FileAccess.Write);
                streamWrite = new StreamWriter(fileStream);
                foreach (string line in lines)
                {
                    if (String.IsNullOrEmpty(line.Replace("\n", "").Replace("\r", "")))
                    {
                        continue;
                    }
                    string[] splitline = line.Replace("\n", "").Replace("\r", "").Split(',');
                    if (String.Compare(splitline[1], this.Iban) == 0)
                    {
                        streamWrite.WriteLine("{0},{1},{2},{3}", splitline[0], splitline[1], this.Currency.ToString("00000.00"), splitline[3]);
                    }
                    else
                    {
                        streamWrite.WriteLine("{0},{1},{2},{3}", splitline[0], splitline[1], splitline[2], splitline[3]);
                    }
                }
                streamWrite.Close();
                fileStream.Close();
            }
            #pragma warning disable CS0168
            catch (Exception exception){
                #pragma warning restore CS0168
                if (streamReader != null)
                    streamReader.Close();
                if (streamWrite != null)
                    streamWrite.Close();
                if (fileStream != null)
                    fileStream.Close();
                this.Read();
                throw new Error("Dedect Problem For File Operation That Process is invalid.");
            }
        }
    }
    internal class Tl : Money
    {
        public Tl(string iban, double currency)
        {
            this.Type = "TL";
            this.Iban = iban;
            this.Currency = currency;
        }
        internal override void TakeMoneyByEft(double willSend, string Type)
        {
            if (String.Compare("TL", Type) == 0)
            {
                this.Currency += willSend;
            }
            else
            {
                this.Currency += willSend * Exchange[Type];
            }
            this.Update();
        }
    }
    internal class Euro : Money
    {
        public Euro(string iban, double currency)
        {
            this.Type = "EURO";
            this.Iban = iban;
            this.Currency = currency;
        }
        internal override void TakeMoneyByEft(double willSend, string Type)
        {
            if (String.Compare("TL", Type) == 0)
            {
                this.Currency += willSend/ Exchange["EURO"];
            }
            else
            {
                this.Currency += (willSend * Exchange[Type])/Exchange["EURO"];
            }
           this.Update();
        }
    }
    internal class Usd : Money
    {
        public Usd(string iban, double currency)
        {
            this.Type = "USD";
            this.Iban = iban;
            this.Currency = currency;
        }
        internal override void TakeMoneyByEft(double willSend, string Type)
        {
            if (String.Compare("TL", Type) == 0)
            {
                this.Currency += willSend / Exchange["USD"];
            }
            else
            {
                this.Currency += (willSend * Exchange[Type]) / Exchange["USD"];
            }
            this.Update();
        }
    }
}
