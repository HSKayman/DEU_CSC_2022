using System;

namespace OOP_Visa_2017280030
{
    class Program
    {
        static void Main(string[] args)
        {
            BookingProcess.DefaultShowInfo();
            Console.WriteLine("Please Choose!");
            Console.WriteLine("1 - Booking Ticket Now!");
            Console.WriteLine("Other Button - Exit!");
            if (Console.ReadLine()== "1")
            {
                Console.WriteLine("Do you have got a Discounted Code[Y/(other button)]?");
                if (String.Compare(Console.ReadLine().ToUpper(),"Y")==0)
                    BookingProcess.GetDTicket();
                else
                    BookingProcess.GetTicket();
            } 
        }
    }
}
