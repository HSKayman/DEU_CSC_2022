using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace OOP_Visa_2017280030
{
    internal class Chair
    {
        private bool isEmpty;
        private int queue;
        private int chairNo;
        internal int Queue
        {
            get { return queue; } 
            set {queue = value; }
        }
        
        internal int ChairNo
        {
            get { return chairNo;}
            set { chairNo = value;}
        }
        internal Chair()
        {
            this.isEmpty = true;
        }
        
        internal bool MakeFull(int seans, int salonNo)
        {
            if (true == FileOperations.SearchforControl(seans, salonNo, this.queue, this.chairNo))
            {
                this.isEmpty = false;
                return true;
            }
            return false;
        }
        internal bool MakeFull()
        {
            this.isEmpty = false;
            return true;
        }
    }
}

