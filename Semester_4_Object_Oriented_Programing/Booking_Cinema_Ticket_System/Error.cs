using System;
using System.Collections.Generic;
using System.Text;
using System.Security;
using System.IO;

namespace OOP_Visa_2017280030
{
    internal class Error: Exception
    {
        internal Error(string message): base(message)
        {

        }
        static internal void TryCatch(Action action)
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
        static internal void TryCatchArg(Action action)
        {
            try
            {
                action.Invoke();
            }
            catch (ArgumentNullException exception)
            {
                Console.WriteLine(exception.Message);
            }
            catch(ArgumentException exception)
            {
                Console.WriteLine(exception.Message);
            }
            catch (Exception exception)
            {
                Console.WriteLine(exception.Message);
            }
        }
        static internal void TryCatchFile(Action action)
        {
            try
            {
                action.Invoke();
            }
            catch (FileNotFoundException)
            {
                Console.WriteLine("Could not found file but it maked new!!!!!");
                FileOperations.GenerateNewCinema();
            }
            catch (DirectoryNotFoundException exception)
            {
                Console.WriteLine(exception.Message);
            }
            catch (ArgumentOutOfRangeException exception)
            {
                Console.WriteLine(exception.Message);
            }
            catch (SecurityException exception)
            {
                Console.WriteLine(exception.Message);
            }
            catch (NotSupportedException exception)
            {
                Console.WriteLine(exception.Message);
            }
            catch (Exception exception)
            {
                Console.WriteLine(exception.Message);
            }
        }
    }
}
