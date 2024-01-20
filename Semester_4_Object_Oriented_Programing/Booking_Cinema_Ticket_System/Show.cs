using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace OOP_Visa_2017280030
{
    internal class Show
    {
        private string movieName;
        private int seans;
        private DateTime dateTime;
        private int salonNo;
        internal List<Chair> chairs;

        internal string MovieName
        {
            get
            {
                return movieName;
            }
            set
            {
                movieName = value;
            }
        }
        internal int Seans
        {
            get
            {
                return seans;
            }
            set
            {
                if(value>0)
                    seans = value;
            }
        }
        internal DateTime SetTime
        {
            get
            {
                return dateTime;
            }
            set
            {
                dateTime = value;
            }
        }
        internal int SalonNo
        {
            get
            {
                return salonNo;
            }
            set
            {
                if(value>0)
                    salonNo = value;
            }
        }
        internal Show(int numberOfQueue, int numberOfChairs)
        {
            this.chairs = new List<Chair>();
            for (int i = 0; i < numberOfChairs; ++i) 
            {
                Chair chair = new Chair();
                chair.ChairNo = ((i + 1) % numberOfQueue) + 1;
                chair.Queue = (i/ numberOfQueue)+1;
                chairs.Add(chair);
            }
        }
    }
}
