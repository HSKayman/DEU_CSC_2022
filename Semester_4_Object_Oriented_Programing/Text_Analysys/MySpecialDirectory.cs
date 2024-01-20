using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.IO;
using System.Text;

namespace _2017280030_OOP_HomeWorkIII
{
    class MySpecialDirectory<T, U>
    {
        internal List<T> key;
        internal List<U> value;
        internal int count;
        internal MySpecialDirectory()
        {
            key = new List<T>();
            value = new List<U>();
            count = 0;
            Error.ErrorAll(() =>
            {
                if (key is null || value is null || count!=0)
                {
                    throw new Error("There is a Problem in Memory");
                }
            });
        }
        internal void Add(T ikey, U ivalue)
        {
            key.Add(ikey);
            value.Add(ivalue);
            count += 1;
        }
        internal (T,U) GetValue(int index)
        {
            if (index > count - 1)
            {
                return (default(T), default(U));
            }
            return (key[index], value[index]);
        }
        internal void PrintValue()
        {
            for(int i=0;i<count;++i)
                Console.WriteLine("{0}:        {1}", key[i], value[i]);
        }
    }
}
