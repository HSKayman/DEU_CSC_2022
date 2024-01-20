using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017280030_OOP_Final
{
    internal class Exchange<T, U> : Dictionary<T, U>  
    {
        internal void ChangeExchange(double usd,double euro)//For Online
        {
            Money.Exchange["USD"] = usd;
            Money.Exchange["EURO"] = euro;
        }
    }
}
