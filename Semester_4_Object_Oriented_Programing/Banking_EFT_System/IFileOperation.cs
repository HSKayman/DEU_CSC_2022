using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017280030_OOP_Final
{
    internal interface IFileOperation
    {
        void Read();
        bool Check(string key);
        void Update();
    }
}
