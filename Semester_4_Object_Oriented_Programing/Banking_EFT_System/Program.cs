using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2017280030_OOP_Final
{
    static class Program
    {
         static public Login login;
        [STAThread]
        static void Main()
        {
            DefaulttMoney(7.1094, 7.9283);
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            login = new Login();
            Application.Run(login);
        }
         static void DefaulttMoney(double Usd, double Euro)
        {
            Money.Exchange.Add("USD", Usd);
            Money.Exchange.Add("EURO", Euro);
        }
    }
}
