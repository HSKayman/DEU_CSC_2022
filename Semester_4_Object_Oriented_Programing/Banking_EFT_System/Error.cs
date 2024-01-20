using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017280030_OOP_Final
{
    class Error:Exception
    {
        public Error(string message) : base(message)
        {

        }
    }
}
