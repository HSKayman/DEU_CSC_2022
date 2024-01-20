using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Security;
using System.Security.Cryptography;
using System.Windows.Forms;

namespace _2017280030_OOP_Final
{
    static internal class FileOperations
    {
        static internal string PasswordToHash(string password)
        {
            var willHash = Encoding.UTF8.GetBytes(password);
            using (SHA512 sha = new SHA512Managed())
            {
                var hashedPassword = sha.ComputeHash(willHash);
                var hashed = new StringBuilder(128);
                foreach (var Byte in hashedPassword)
                    hashed.Append(Byte.ToString("X2"));
                return hashed.ToString();
            }
        }
        static internal void CreateDefaultAuth(string method)
        {
            FileStream fileStream;
            if (!Directory.Exists(@"c:\\final"))
            {
                Directory.CreateDirectory(@"c:\\final");
            }
            else if (!File.Exists(@"c:\\final\\auth.txt")||String.Compare(method,"force")==0)
            {
                fileStream = new FileStream(@"c:\\final\\auth.txt", FileMode.Create, FileAccess.Write);
                StreamWriter streamWrite = new StreamWriter(fileStream);
                streamWrite.WriteLine("326785,{0}", PasswordToHash("IsmB1982"));
                streamWrite.WriteLine("400129,{0}", PasswordToHash("12Hrst34"));
                streamWrite.WriteLine("388000,{0}", PasswordToHash("zb123456"));
                streamWrite.WriteLine("201005,{0}", PasswordToHash("Mordor99"));
                streamWrite.WriteLine("222300,{0}", PasswordToHash("12345678"));
                streamWrite.Flush();
                streamWrite.Close();
                fileStream.Close();
            }
        }
        static internal void CreateDefaultClient(string method)
        {
            FileStream fileStream;
            if (!Directory.Exists(@"c:\\final"))
            {
                Directory.CreateDirectory(@"c:\\final");
            }
            else if (!File.Exists(@"c:\\final\\client.txt")||String.Compare(method, "force") == 0)
            {
                fileStream = new FileStream(@"c:\\final\\client.txt", FileMode.Create, FileAccess.Write);
                StreamWriter streamWrite = new StreamWriter(fileStream);
                streamWrite.WriteLine("201005,TR610032455466661200201005,00666.66,TL");
                streamWrite.WriteLine("201005,TR300032455410080002301005,00350.00,USD");
                streamWrite.WriteLine("326785,TR610003200013900000326785,10000.00,TL");
                streamWrite.WriteLine("326785,TR300003200016420000326785,00350.00,EURO");
                streamWrite.WriteLine("388000,TR610007222250001200388000,19150.00,TL");
                streamWrite.WriteLine("388000,TR300007222249000001388000,00052.93,EURO");
                streamWrite.WriteLine("388000,TR300008222266600002388000,02850.00,USD");
                streamWrite.WriteLine("400129,TR610008324560000000400129,02980.45,TL");
                streamWrite.WriteLine("222300,TR610008244444444444444400,22850.00,USD");
                streamWrite.Flush();
                streamWrite.Close();
                fileStream.Close();
            }
        }
        static internal void CreatePersonalizedFile(string method)
        {
            FileStream fileStream;
            if (!Directory.Exists(@"c:\\final"))
            {
                Directory.CreateDirectory(@"c:\\final");
            }
            else if (!File.Exists(@"c:\\final\\personalized.txt") || String.Compare(method, "force") == 0)
            {
                fileStream = new FileStream(@"c:\\final\\personalized.txt", FileMode.Create, FileAccess.Write);
                StreamWriter streamWrite = new StreamWriter(fileStream);
                streamWrite.WriteLine("Personal,201005,Naz Gul,Ucan,0,{0}", (new DateTime(2000, 1, 1, 1, 1, 1)).ToString());
                streamWrite.WriteLine("Personal,326785,Ismail,Borazan,0,{0}", (new DateTime(2000, 1, 1, 1, 1, 1)).ToString());
                streamWrite.WriteLine("Personal,400129,Kamile,Hursitgilogullari,0,{0}", (new DateTime(2000, 1, 1, 1, 1, 1)).ToString());
                streamWrite.WriteLine("Personal,388000,Zebercet,Bak,0,{0}", (new DateTime(2000, 1, 1, 1, 1, 1)).ToString());
                streamWrite.WriteLine("Company,222300,Akdeniz Holding,0,{0}", (new DateTime(2000, 1, 1, 1, 1, 1)).ToString());
                streamWrite.Flush();
                streamWrite.Close();
                fileStream.Close();
            }
        }
        static internal void ReadToPersolanized()
        {
            FileStream fileStream = new FileStream(@"c:\\final\\personalized.txt", FileMode.Open, FileAccess.Read);
            StreamReader streamReader = new StreamReader(fileStream);
            string line = streamReader.ReadLine();
            if (line == null)
            {
                streamReader.Close();
                fileStream.Close();
                new Error("Personalized File Destoryed.");
            }
            try
            {
                while (line != null)
                {

                    string[] lines = line.Split(',');
                    if (String.Compare(lines[0], "Personal") == 0)
                    {
                        AccountHolders.AllClients.Add(
                            new PersonalClient
                            {
                                accountNumber = lines[1],
                                Name = lines[2],
                                Surname = lines[3],
                                IsLock = !(String.Compare(lines[4], "0") == 0),
                                LockedTime = Convert.ToDateTime(lines[5])
                            });
                    }
                    else
                    {
                        AccountHolders.AllClients.Add(
                            new CompanyClient
                            {
                                accountNumber = lines[1],
                                CompanyName = lines[2],
                                IsLock = !(String.Compare(lines[3], "0") == 0),
                                LockedTime = Convert.ToDateTime(lines[4])
                            });
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
                FileOperations.CreatePersonalizedFile("force");
                AccountHolders.AllClients.Clear();
                try
                {
                    (new PersonalClient()).Read();
                }
#pragma warning disable CS0168
                catch (Exception exceptions)
                {
#pragma warning restore CS0168
                }
                throw new Error("Personalized File Destoried,But Recoveried Old File!");
            }
        }
        static internal void ReadToAuth()
        {
            try
            {
                FileStream fileStream = new FileStream(@"c:\\final\\auth.txt", FileMode.Open, FileAccess.Read);
                StreamReader streamReader = new StreamReader(fileStream);
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
                    BankAccount client = AccountHolders.FindClient(lines[0], "Account Number");
                    if (client == null)
                    {
                        streamReader.Close();
                        fileStream.Close();
                        throw new Error("");
                    }
                    client.Password = lines[1];
                    line = streamReader.ReadLine();
                }
                streamReader.Close();
                fileStream.Close();
            }
#pragma warning disable CS0168
            catch (Exception exception)
#pragma warning restore CS0168
            {
                FileOperations.CreateDefaultAuth("force");
                ReadToAuth();
                throw new Error("Auth File Destoried. But Recoveried File");
            }
        }
    }
}
