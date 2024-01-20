using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017280030_OOP_Final
{
    internal static class AccountHolders
    {
        internal static List<BankAccount> AllClients = new List<BankAccount>();
        internal static BankAccount FindClient(string key, string method)
        {
            if (String.Compare(method, "Name") == 0)
            {
                foreach (BankAccount account in AllClients)
                {
                    if (String.Compare(account.GetName(), key) == 0)
                    {
                        return account;
                    }
                }
            }
            else if (String.Compare(method, "Account Number") == 0)
            {
                foreach (BankAccount account in AllClients)
                {
                    if (String.Compare(account.accountNumber, key) == 0)
                    {
                        return account;
                    }
                }
            }
            return null;
        }
        internal static List<string> OtherName(string accountNumber)
        {
            List<string> others = new List<string>();
            foreach (BankAccount account in AllClients)
            {
                if (String.Compare(account.accountNumber, accountNumber) != 0)
                {
                    others.Add(account.GetName());
                }
            }
            return others;
        }
    }
}
