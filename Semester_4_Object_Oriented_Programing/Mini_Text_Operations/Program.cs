using System;

namespace _2017280030_OOP_HomeworkII
{
    class Program
    {
        static void Main()
        {
            bool flag = true;
            while (flag)
            {
                Error.ErrorAll(() => {
                    System.Threading.Thread.Sleep(1000);
                    Console.Clear();
                    Console.WriteLine("1-Open File,Read And Serializing");
                    Console.WriteLine("2-Deserializing and Print on Screen");
                    Console.WriteLine("3-Exit");
                    int a=Convert.ToInt32(Console.ReadLine());
                    if (a < 1 || a > 3)
                    {
                        throw new Error("Wrong Button!");
                        
                    }
                    else if (a == 1)
                    {
                        TextInfo textInfo = TextInfo.Reader();
                        if (textInfo == null)
                            Error.ErrorAll(() =>
                            {
                                throw new Error("There was a problem!");
                            });
                        else
                            TextInfo.Serialing(textInfo);
                    }
                    else if (a == 2)
                    {
                        TextInfo textInfo_II = new TextInfo();
                        textInfo_II.Print();
                    }
                    else
                        flag = false;
                });
                
            }
        }
    }
}
