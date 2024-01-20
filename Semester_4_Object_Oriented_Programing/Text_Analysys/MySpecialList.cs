using System;
using System.Collections.Generic;
using System.Text;

namespace _2017280030_OOP_HomeWorkIII
{
    internal class MySpecialList<T>:List<T>
    {
        internal HashSet<T> uniqueValueList;
        internal void ComputeToUniqieValueList()
        {
            Error.ErrorAll(() =>
            {
                if (this is null)
                {
                    throw new Error("Unique Values are Empty");
                }
                foreach (T word in this)
                    if (!uniqueValueList.Contains(word))
                        uniqueValueList.Add(word);
            });
            
        }
        internal void PrepareToHashSet()
        {
            Error.ErrorAll(() =>
            {
                uniqueValueList = new HashSet<T>();
                if (uniqueValueList is null)
                {
                    throw new Error("There is a Problem in Memory");
                }
            });
        }
    }
}
