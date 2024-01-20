using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace _2017280030_OOP_HomeworkII
{
    internal class Error:Exception
    {
        internal Error(string message):base(message)
        {

        }
        internal static void ErrorAll(Action action)
        {
            try
            {
                action.Invoke();
            }
            catch (Exception exception)
            {
                Console.WriteLine(exception.Message);
            }
        } 
    }
}
