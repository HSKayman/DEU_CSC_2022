using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace OOP_Visa_2017280030
{
    static public class FileOperations
    {
        static public void GenerateNewCinema()
        {
            Console.WriteLine("Creating a New cinema.txt");
            Error.TryCatchFile(() =>
            {
                FileStream fileStream = new FileStream(@"cinema.txt", FileMode.Create, FileAccess.Write);
                Error.TryCatchArg(() =>
                {
                    StreamWriter streamWrite = new StreamWriter(fileStream);
                    Random random = new Random();
                    string[] boolean = new string[] { "Empty", "Full", "Empty" };
                    for (int i = 1; i <= 5; ++i)
                    {
                        for (int j = 1; j <= 5; ++j)
                        {
                            for (int k = 1; k <= 10; ++k)
                            {
                                for (int l = 1; l <= 10; ++l)
                                {
                                    streamWrite.WriteLine(i.ToString() + "," + j.ToString() + "," + k.ToString() + "," + l.ToString() + "," + boolean[random.Next(3)]);
                                }
                            }
                        }
                    }
                    streamWrite.Flush();
                    streamWrite.Close();
                });
                fileStream.Close();
                
            });
            StroagetoRam();
        }
        internal static void StroagetoRam()//Hocam Biligyorum madem dosyadan okuyorsun kontrol icin niye ihtiyac var ben classlari doldurmak icin yapiyorum hocam
        {
            bool boolean = false;
            Error.TryCatchFile(() =>
            {
                FileStream fileStream = new FileStream(@"cinema.txt", FileMode.Open, FileAccess.Read);
                Error.TryCatchArg(() =>
                {
                    StreamReader streams = new StreamReader(fileStream);
                    string line = streams.ReadLine();
                    Show show;
                    Chair chair;
                    while (line != null)
                    {
                        string[]lineSplit =line.Split(",");
                        try
                        {
                        (chair,show)=BookingProcess.FindShow(Convert.ToInt32(lineSplit[0]), Convert.ToInt32(lineSplit[1]), Convert.ToInt32(lineSplit[2]), Convert.ToInt32(lineSplit[3]));
                            if (String.Compare(lineSplit[4], "Full")==0){
                                chair.MakeFull();
                            }
                        }catch(IndexOutOfRangeException exception)
                        {
                            Console.WriteLine(exception.Message);
                            boolean = true;
                            break;
                        }catch(NullReferenceException exception)
                        {
                            boolean = true;
                            Console.WriteLine(exception.Message);
                            break;
                        }catch(Exception exception)
                        {
                            boolean = true;
                            Console.WriteLine(exception.Message);
                            break;
                        }
                        line = streams.ReadLine();
                    }
                    
                    streams.Close();
                });
                fileStream.Close();
            });
            if (boolean == true)
            {
                Console.WriteLine("System is Crashed.");
                Console.WriteLine("Please Try Again");
                GenerateNewCinema();
            }
        }
        internal static bool SearchforControl(int seans, int salonNo, int queue, int chair)
        {
            int i = 1;
            bool boolean = false;
            Error.TryCatchFile(() =>
            {
                FileStream fileStream = new FileStream(@"cinema.txt", FileMode.Open, FileAccess.ReadWrite);
                Error.TryCatchArg(() =>
                {
                    StreamReader streams = new StreamReader(fileStream);
                    
                    string line = streams.ReadLine();
                    
                    if (line == null)
                    {
                        Console.WriteLine("System is Crashed.");
                        streams.Close();
                        fileStream.Close();
                        GenerateNewCinema();
                    }
                    while (line != null)
                    {
                        try
                        {
                            string[] linesplit = line.Split(",");
                            if(linesplit[0].IsNumeric()&& linesplit[1].IsNumeric() && linesplit[2].IsNumeric() && linesplit[3].IsNumeric() && !linesplit[4].IsNumeric())
                            {
                                
                            }
                            else
                            {
                                Console.WriteLine("There is some problem Inside System.");
                                streams.Close();
                                fileStream.Close();
                                GenerateNewCinema();
                            }
                        }
                        catch (IndexOutOfRangeException)
                        {
                            Console.WriteLine("There is some problem Inside System.");
                            streams.Close();
                            fileStream.Close();
                            GenerateNewCinema();
                        }
                        if (String.Compare(line, (seans.ToString() + "," + salonNo.ToString() + "," + queue.ToString() + "," + chair.ToString() + "," + "Empty")) == 0)
                        {
                            Console.WriteLine("Selected Seat is Empty");
                            boolean = true;
                            break;
                        }
                        else if (String.Compare(line, (seans.ToString() + "," + salonNo.ToString() + "," + queue.ToString() + "," + chair.ToString() + "," + "Full")) == 0)
                        {
                            Console.WriteLine("Selected Seat is Full!");
                            break;
                        }
                        ++i;
                        line = streams.ReadLine();
                    }
                    streams.Close();
                });
                fileStream.Close();
            });
            if (boolean == true)
            {
                Updater(seans, salonNo, queue, chair, i);
            }
            return boolean;
        }
        internal static void Updater(int seans, int salonNo, int queue, int chair,int i)
        {
            Error.TryCatchFile(() =>
            {
                try
                {
                    string[] line = File.ReadAllLines(@"cinema.txt");
                    line[i - 1] = ((seans.ToString() + "," + salonNo.ToString() + "," + queue.ToString() + "," + chair.ToString() + "," + "Full"));
                    File.WriteAllLines(@"cinema.txt", line);
                }catch(IndexOutOfRangeException exception)
                {
                    Console.WriteLine(exception.Message);
                }
            });
            Console.WriteLine("cinema.txt is upgraded");
        }
        public static bool IsNumeric(this string text) => int.TryParse(text, out _);
    }
}
