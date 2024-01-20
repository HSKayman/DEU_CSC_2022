using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace OOP_Visa_2017280030
{
    internal class BookingProcess
    {
        static public List<Show> shows = new List<Show>();
        static public string[] movieName = new string[5] { "Avangers", "Spiderman", "Godfather", "Harry Potter", "The Rings Of The King" };
        static public string[] time = new string[5] { "10:00", "13:00", "16:00", "19:00", "22:00" };
        static public void DefaultShowInfo()
        {
            shows.Clear();
            for (int j = 0; j < 5; j++)
            {
                for (int i = 0; i < 5; ++i)
                {
                    Show show = new Show(10, 100);
                    show.MovieName = movieName[i];
                    show.Seans = j+1;
                    show.SetTime = Convert.ToDateTime(time[j]);
                    show.SalonNo = i+1;
                    shows.Add(show);
                }
            }
            FileOperations.StroagetoRam();
        }
        internal static void GetTicket()
        {
            while (true) { 
                
                Ticket ticket = new Ticket();
                Console.WriteLine("Name :");
                ticket.name = Console.ReadLine();
                Console.WriteLine("Surname :");
                ticket.surname = Console.ReadLine();
                Console.Clear();
                int choosenFilm, choosenTime, choosenQueue, choosenChair;
                while (true)
                {
                    Console.WriteLine("Tc No:");
                    ticket.tcId = Console.ReadLine();
                    Error.TryCatch(() =>
                    {
                        if (ticket.tcId.Length != 11)
                        {
                            throw new Error("Wrong TC ID Please Try Again");
                        }
                    });
                    if (ticket.tcId.Length == 11)
                    {
                        break;
                    }
                }
                Console.Clear();
                while (true) {
                    Console.WriteLine("Please Choose Film:");
                    for (int i = 0; i < 5; ++i)
                    {
                        Console.WriteLine("{0}: {1}", (i + 1), movieName[i]);
                    }
                    choosenFilm = Convert.ToInt32(Console.ReadLine());
                    Error.TryCatch(() =>
                    {
                        if (choosenFilm <= 0 || choosenFilm > 5)
                        {
                            throw new Error("Wrong Choose Please Try Again");
                        }
                    });
                    if (choosenFilm > 0 && choosenFilm <= 5)
                    {
                        break;
                    }
                }
                Console.Clear();
                while (true)
                {
                    Console.WriteLine("Please Choose Time:");
                    for (int i = 0; i < 5; ++i)
                    {
                        Console.WriteLine("{0}: {1}", (i + 1), time[i]);
                    }
                    choosenTime = Convert.ToInt32(Console.ReadLine());
                    Error.TryCatch(() =>
                    {
                        if (choosenTime <= 0 || choosenTime > 5)
                        {
                            throw new Error("Wrong Choose Please Try Again");
                        }
                    });
                    if (choosenTime > 0 && choosenTime <= 5)
                    {
                        break;
                    }
                }
                Console.Clear();
                while (true)
                {
                    Console.WriteLine("Please Choose Queue:");
                    for (int i = 0; i < 10; ++i)
                    {
                        Console.Write((i + 1) + " ");
                    }
                    Console.Write(" : ");
                    choosenQueue = Convert.ToInt32(Console.ReadLine());
                    Error.TryCatch(() =>
                    {
                        if (choosenQueue <= 0 || choosenQueue > 10)
                        {
                            throw new Error("Wrong Choose Please Try Again");
                        }
                    });
                    if (choosenQueue > 0 && choosenQueue <= 10)
                    {
                        break;
                    }
                }
                Console.Clear();
                while (true)
                {
                    Console.WriteLine("Please Choose Chair Number:");
                    for (int i = 0; i < 10; ++i)
                    {
                        Console.Write((i + 1) + " ");
                    }
                    Console.Write(" : ");
                    choosenChair = Convert.ToInt32(Console.ReadLine());
                    Error.TryCatch(() =>
                    {
                        if (choosenChair <= 0 || choosenChair > 10)
                        {
                            throw new Error("Wrong Choose Please Try Again");
                        }
                    });
                    if (choosenChair > 0 && choosenChair < 10)
                    {
                        break;
                    }
                }
                Console.Clear();
                (ticket.chair, ticket.show) = FindShow(choosenTime, choosenFilm, choosenQueue, choosenChair);
                Error.TryCatch(() =>
                {
                    if (ticket.chair == null || ticket.show == null)
                    {
                        throw new Error("Some errors have occurred in the system");
                    }
                });

                if (ticket.chair.MakeFull(choosenTime, choosenFilm) == true)
                {
                    Console.WriteLine("Booking is Complete!");
                    Console.WriteLine("Do you want to ticket [Y/(other button)]?");
                    if (String.Compare(Console.ReadLine().ToString().ToUpper(), "Y") == 0)
                        ticket.Print();
                }
                Console.Clear();
                Console.WriteLine("Do you want to book a another cinema ticket [Y/(other button)]?");
                if (String.Compare(Console.ReadLine().ToString().ToUpper(), "Y") == 0)
                    continue;
                else
                    break;
                
            }
        }
        internal static void GetDTicket()
        {
            DiscountedTicket ticket = new DiscountedTicket();
            while (true)
            {
                Console.WriteLine("Discounted code : ");
                string code = Console.ReadLine();
                if (String.Compare(code, "FREE") == 0)
                {
                    Random random = new Random();
                    ticket.discountedCode = "FREE";
                    ticket.discounted = random.Next(100);
                    ticket.MakeDiscounted();
                }
                else
                {
                    ticket.discountedCode = "Lie!";
                    ticket.discounted = 300;
                    ticket.MakeDiscounted();
                }
                Console.Clear();
                Console.WriteLine("Name :");
                ticket.name = Console.ReadLine();
                Console.WriteLine("Surname :");
                ticket.surname = Console.ReadLine();
                Console.Clear();
                int choosenFilm, choosenTime, choosenQueue, choosenChair;
                while (true)
                {
                    Console.WriteLine("Tc No:");
                    ticket.tcId = Console.ReadLine();
                    Error.TryCatch(() =>
                    {
                        if (ticket.tcId.Length != 11)
                        {
                            throw new Error("Wrong TC ID Please Try Again");
                        }
                    });
                    if (ticket.tcId.Length == 11)
                    {
                        break;
                    }
                }
                Console.Clear();
                while (true)
                {
                    Console.WriteLine("Please Choose Film:");
                    for (int i = 0; i < 5; ++i)
                    {
                        Console.WriteLine("{0}: {1}", (i + 1), movieName[i]);
                    }
                    choosenFilm = Convert.ToInt32(Console.ReadLine());
                    Error.TryCatch(() =>
                    {
                        if (choosenFilm <= 0 || choosenFilm > 5)
                        {
                            throw new Error("Wrong Choose Please Try Again");
                        }
                    });
                    if (choosenFilm > 0 && choosenFilm <= 5)
                    {
                        break;
                    }
                }
                Console.Clear();
                while (true)
                {
                    Console.WriteLine("Please Choose Time:");
                    for (int i = 0; i < 5; ++i)
                    {
                        Console.WriteLine("{0}: {1}", (i + 1), time[i]);
                    }
                    choosenTime = Convert.ToInt32(Console.ReadLine());
                    Error.TryCatch(() =>
                    {
                        if (choosenTime <= 0 || choosenTime > 5)
                        {
                            throw new Error("Wrong Choose Please Try Again");
                        }
                    });
                    if (choosenTime > 0 && choosenTime <= 5)
                    {
                        break;
                    }
                }
                Console.Clear();
                while (true)
                {
                    Console.WriteLine("Please Choose Queue:");
                    for (int i = 0; i < 10; ++i)
                    {
                        Console.Write((i + 1) + " ");
                    }
                    Console.Write(" : ");
                    choosenQueue = Convert.ToInt32(Console.ReadLine());
                    Error.TryCatch(() =>
                    {
                        if (choosenQueue <= 0 || choosenQueue > 10)
                        {
                            throw new Error("Wrong Choose Please Try Again");
                        }
                    });
                    if (choosenQueue > 0 && choosenQueue <= 10)
                    {
                        break;
                    }
                }
                Console.Clear();
                while (true)
                {
                    Console.WriteLine("Please Choose Chair Number:");
                    for (int i = 0; i < 10; ++i)
                    {
                        Console.Write((i + 1) + " ");
                    }
                    Console.Write(" : ");
                    choosenChair = Convert.ToInt32(Console.ReadLine());
                    Error.TryCatch(() =>
                    {
                        if (choosenChair <= 0 || choosenChair > 10)
                        {
                            throw new Error("Wrong Choose Please Try Again");
                        }
                    });
                    if (choosenChair > 0 && choosenChair < 10)
                    {
                        break;
                    }
                }
                (ticket.chair, ticket.show) = FindShow(choosenTime, choosenFilm, choosenQueue, choosenChair);
                Error.TryCatch(() =>
                {
                    if (ticket.chair == null || ticket.show == null)
                    {
                        throw new Error("Some errors have occurred in the system");
                    }
                });
                
                if (ticket.chair.MakeFull(choosenTime, choosenFilm) == true)
                {
                    Console.WriteLine("Booking is Complete!");
                    Console.WriteLine("Do you want to ticket [Y/(other button)]?");
                    if (String.Compare(Console.ReadLine().ToString().ToUpper(), "Y") == 0)
                        ticket.Print();
                }
                Console.Clear();
                Console.WriteLine("Do you want to book a another cinema ticket [Y/(other button)]?");
                if (String.Compare(Console.ReadLine().ToString().ToUpper(), "Y") == 0)
                    continue;
                else
                    break;

            }
        }
        internal static (Chair, Show) FindShow(int seans,int salonNo,int Queue,int chairNo)
        {
            foreach (Show show in shows)
            {
                if (show.SalonNo == salonNo && show.Seans == seans)
                {
                    foreach (Chair chair in show.chairs)
                    {
                        if (chair.Queue == Queue && chair.ChairNo == chairNo)
                        {
                            return (chair,show);
                        }
                    }
                }
            }
            return (null, null);
        }
    }
}
