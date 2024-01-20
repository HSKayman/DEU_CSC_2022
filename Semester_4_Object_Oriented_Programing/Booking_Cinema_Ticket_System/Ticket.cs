using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace OOP_Visa_2017280030
{
    class Ticket:IPrint
    {
        internal Chair chair { get; set; }
        internal string name{ get; set; }
        internal string surname{ get; set; }
        internal string tcId { get; set; }
        internal Show show{ get; set; }
        internal double price = 10;
        public void Print()
        {
            Error.TryCatchFile(() =>
            {
                string ticketname = @"ticket.txt";
                FileStream fileStream;
                if (File.Exists(ticketname))
                {
                    fileStream = new FileStream(ticketname, FileMode.Append, FileAccess.Write);
                }
                else
                {
                    fileStream = new FileStream(ticketname, FileMode.Create, FileAccess.Write);
                }
                
                
                Error.TryCatchArg(() =>
                {
                    StreamWriter streamWrite = new StreamWriter(fileStream);
                    streamWrite.WriteLine("Name : " + this.name);
                    streamWrite.WriteLine("Surname : " + this.surname);
                    streamWrite.WriteLine("TC : " + this.tcId);
                    streamWrite.WriteLine("Movie Name : " + this.show.MovieName);
                    streamWrite.WriteLine("Seans No : " + this.show.Seans.ToString() + "   Time :" + Convert.ToString(this.show.SetTime));
                    streamWrite.WriteLine("Salon No : " + this.show.SalonNo.ToString());
                    streamWrite.WriteLine("Chair Queue : " + this.chair.Queue.ToString());
                    streamWrite.WriteLine("Chair No : " + this.chair.ChairNo.ToString());
                    streamWrite.WriteLine("Price : " + this.price.ToString() + "$");
                    streamWrite.Flush();
                    streamWrite.Close();
                });
                fileStream.Close();
            });
            Console.WriteLine("Ticket is Printing.");
        }
    }
    class DiscountedTicket: Ticket
    {
        internal string discountedCode { get; set; }
       internal int discounted { get; set; }
        public void Print()
        {
            Error.TryCatchFile(() =>
            {
                string ticketname = @"ticket.txt";
                FileStream fileStream;
                if (File.Exists(ticketname))
                {
                    fileStream = new FileStream(ticketname, FileMode.Append, FileAccess.Write);
                }
                else
                {
                    fileStream = new FileStream(ticketname, FileMode.Create, FileAccess.Write);
                }
                Error.TryCatchArg(() =>
                {
                    StreamWriter streamWrite = new StreamWriter(fileStream);
                    streamWrite.WriteLine("Name : " + this.name);
                    streamWrite.WriteLine("Surname : " + this.surname);
                    streamWrite.WriteLine("TC : " + this.tcId);
                    streamWrite.WriteLine("Movie Name : " + this.show.MovieName);
                    streamWrite.WriteLine("Seans No : " + this.show.Seans.ToString() + "   Time :" + Convert.ToString(this.show.SetTime));
                    streamWrite.WriteLine("Salon No : " + this.show.SalonNo.ToString());
                    streamWrite.WriteLine("Chair Queue : " + this.chair.Queue.ToString());
                    streamWrite.WriteLine("Chair No : " + this.chair.ChairNo.ToString());
                    streamWrite.WriteLine("Price : " + this.price.ToString() + "$");
                    streamWrite.WriteLine("Discount Code : " + this.discountedCode);
                    streamWrite.WriteLine("Discount :  %" + (this.discounted));
                    streamWrite.Flush();
                    streamWrite.Close();
                });
                fileStream.Close();
            });
            Console.WriteLine("Ticket is Printing.");
        }
        public void MakeDiscounted()
        {
            this.price *= discounted / 100.0;
        }
    }
}
