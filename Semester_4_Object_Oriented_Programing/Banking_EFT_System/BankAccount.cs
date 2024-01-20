using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;
using System.Windows.Forms;
using System.IO;
using System.Runtime.Remoting;

namespace _2017280030_OOP_Final
{
    internal abstract class BankAccount : IFileOperation
    {
        internal string accountNumber;
        private string password;
        internal string Password
        {
            get { return password; }
            set { password = value; }
        }
        private bool isLock;
        internal bool IsLock{
            get { return isLock; } 
            set{ isLock = value; }        
        }
        private DateTime lockedTime;
        internal DateTime LockedTime
        {
            get { return lockedTime ; }
            set { lockedTime = value; }
        }
        protected List<Money> Accounts;
        internal void Locked() {
            this.lockedTime = System.DateTime.Now;
            isLock = true;
            Update();
        }
        internal void TransferMoney(string iban, string name, string ibanII, string amount)
        {
            Money senderaccount = null;
            foreach (Money account in this.Accounts)
            {
                if (String.Compare(account.Iban, iban) == 0)
                {
                    senderaccount = account;
                    break;
                }
            }
            BankAccount receiver = AccountHolders.FindClient(name, "Name");
            Money receiveraccount = null;
            foreach (Money account in receiver.Accounts)
            {
                if (String.Compare(account.Iban, ibanII) == 0)
                {
                    receiveraccount = account;
                    break;
                }
            }
            try
            {
                if (senderaccount.Check(amount))
                {
                    string type = senderaccount.SendMoneyByEft(Convert.ToDouble(amount));
                    if (String.IsNullOrEmpty(type))
                        throw new Error("You have not got enough money?");
                    receiveraccount.TakeMoneyByEft(Convert.ToDouble(amount), type);
                }
                else
                {
                    throw new Error("You have not got enough money?");
                }
            }
            catch (Exception exception)
            {
                throw new Error(exception.Message);
            }
        }
        internal bool IsLocked()
        {
            if (isLock)
            {
                if (System.DateTime.Now.Subtract(this.lockedTime).TotalDays >= 1)
                {
                    this.isLock = false;
                    Update();
                    return true;
                }
            }
            else
            {
                return true;
            }
            return false;
            
            
        }
        internal string GetBalance()
        {
            string Print = "";
            foreach (Money money in this.Accounts)
            {
                Print += money.GetInfo() + "\n\n";
            }
            return Print;
        }
        internal abstract string GetName();
        internal List<string> GetIbans()
        {
            List<string> ibans = new List<string>();
            foreach (Money money in this.Accounts)
            {
                ibans.Add(money.GetIbanInfo());
            }
            return ibans;
        }
        internal void SetAccounts(Money accounts)
        {
            this.Accounts.Add(accounts);
        }
        public void Read()
        {
            try
            {
                FileOperations.ReadToPersolanized();
                FileOperations.ReadToAuth();
                (new Tl("try", 0.0)).Read();
            }
            catch (Exception exception)
            {
                throw new Error(exception.Message);
            }
        }
        public bool Check(string key)//double check
        {
            bool correct = false;
            if (String.Compare(FileOperations.PasswordToHash(key), this.password) != 0)
            {
                return false;
            }
            FileStream fileStream = null;
            StreamReader streamReader=null;
            try
            {
                if (!File.Exists(@"c:\\final\\auth.txt"))
                {
                    new Error("File not found!");
                }
                fileStream = new FileStream(@"c:\\final\\auth.txt", FileMode.Open, FileAccess.Read);
                streamReader = new StreamReader(fileStream);
                string line = streamReader.ReadLine();
                if (line == null)
                {
                    streamReader.Close();
                    fileStream.Close();
                    new Error("Auth File is Empty.");
                }
                while (line != null)
                {
                    string[] lines = line.Split(',');
                    if (lines[1].Length != 128)
                        throw new Error("");
                    if (String.Compare(lines[0], this.accountNumber) == 0)
                    {
                        if (String.Compare(lines[1], this.password) == 0)
                        {
                            correct = true;
                            break;
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
                streamReader.Close();
                fileStream.Close();
                string errorCode = "";
                try
                {
                    FileOperations.ReadToAuth();
                }catch(Exception exceptions)
                {
                    errorCode = exceptions.Message;
                }
                MessageBox.Show(errorCode+" Please Try Later!", "Problem", MessageBoxButtons.OK);
                return false;
            }
            return correct;
        }
        public void Update()
        {
            FileStream fileStream = null;
            StreamReader streamReader = null;
            StreamWriter streamWrite = null;
            try
            {
                fileStream = new FileStream(@"c:\\final\\personalized.txt", FileMode.Open, FileAccess.Read);
                streamReader = new StreamReader(fileStream);
                string[] lines = streamReader.ReadToEnd().Split('\n');
                streamReader.Close();
                if (lines == null)
                {
                    new Error("Personalized File is Empty.");
                    streamReader.Close();
                    fileStream.Close();
                }
                fileStream = new FileStream(@"c:\\final\\personalized.txt", FileMode.Open, FileAccess.Write);
                streamWrite = new StreamWriter(fileStream);
                foreach (string line in lines)
                {
                    if (String.IsNullOrEmpty(line.Replace("\n", "").Replace("\r", "")))
                    {
                        continue;
                    }
                    string[] splitline = line.Replace("\n", "").Replace("\r", "").Split(',');
                    if (String.Compare(splitline[1], this.accountNumber) == 0)
                    {
                        if (String.Compare(splitline[0], "Personal") == 0)
                        {
                            streamWrite.WriteLine("{0},{1},{2},{3},{4},{5}", splitline[0], splitline[1], splitline[2], splitline[3], isLock ? "1" : "0", lockedTime.ToString());
                        }
                        else
                        {
                            streamWrite.WriteLine("{0},{1},{2},{3},{4}", splitline[0], splitline[1], splitline[2], isLock ? "1" : "0", lockedTime.ToString());
                        }
                    }
                    else
                    {
                        if (String.Compare(splitline[0], "Personal") == 0)
                        {
                            streamWrite.WriteLine("{0},{1},{2},{3},{4},{5}", splitline[0], splitline[1], splitline[2], splitline[3], splitline[4], splitline[5]);
                        }
                        else
                        {
                            streamWrite.WriteLine("{0},{1},{2},{3},{4}", splitline[0], splitline[1], splitline[2], splitline[3], splitline[4]);
                        }
                    }
                }
                streamWrite.Flush();
                streamWrite.Close();
                fileStream.Close();
             #pragma warning disable CS0168
            }
            catch (Exception exception)
            {
                #pragma warning restore CS0168
                if(streamReader!=null)
                    streamReader.Close();
                if(streamWrite!=null)
                    streamWrite.Close();
                if(fileStream!=null)
                    fileStream.Close();
                string errorCode = "";
                try
                {
                    FileOperations.ReadToPersolanized();
                }
                catch (Exception exceptions)
                {
                    errorCode = exceptions.Message;
                    MessageBox.Show(errorCode + "Wrong Logins were forgotten", "Problem", MessageBoxButtons.OK);
                }
            }
        }

    }
    internal class PersonalClient:BankAccount
    {
        internal string Name { get; set; }
        internal string Surname { get; set; }
        internal override string GetName()
        {
            return Name + " " + Surname;
        }
        internal PersonalClient()
        {
            this.Accounts= new List<Money>();
        }
    }
    internal class CompanyClient:BankAccount
    {
        internal string CompanyName { get; set; }
        internal override string GetName()
        {
            return CompanyName;
        }
        internal CompanyClient()
        {
            this.Accounts = new List<Money>();
        }
    }
}
