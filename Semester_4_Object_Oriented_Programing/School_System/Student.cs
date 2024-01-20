using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleStudentInformationSystem
{
    abstract class Student
    {
        private string _id;
        internal string Id{ get { return this._id; } set { this._id = value.ToUpper(); } }
        private string _nameSurname; 
        internal string NameSurname{ get { return this._nameSurname; } set { this._nameSurname = value.ToUpper(); } }
        private string _departmanName;
        internal string DepartmanName{ get { return this._departmanName; } set { this._departmanName = value; } }
        protected List<Lecture> Lectures = new List<Lecture>();

        protected void StartOfPrint()
        {
            Console.WriteLine("\t{0,10}; {1,25}; {2,15}; CumulativeNote->{3}", this.Id, this.NameSurname, this.DepartmanName, CumulativeNote());
        }
        abstract public void Print();
        internal void LectureAdd(string code, string name, double note, int akts = 5)
        {
            Lecture lecture = new Lecture();
            lecture.Code = code;
            lecture.Name = name;
            lecture.Akts = akts;
            lecture.Note = note;
            this.Lectures.Add(lecture);
        }

        protected void LecturePrint()
        {
            foreach (Lecture lecture in this.Lectures)
            {
                Console.WriteLine("\t\t{0,8} {1,30} {2,10} {3}", lecture.Code, lecture.Name,
                    Convert.ToString(lecture.Akts) + " akts", lecture.Note);
            }
            Console.WriteLine();
            Console.WriteLine();
        }
        private (double,double) OptionalParameters(double divided, double divining, double note,int akts=5)
        {
            divided += note * akts;
            divining += akts;
            return (divided, divining);
        }
        private double CumulativeNote()
        {
            double divining = new double();
            double divided = new double();
            
            foreach (Lecture lecture in this.Lectures)
            {
                (divided,divining)=OptionalParameters(divided,divining,lecture.Note, lecture.Akts);
            }
            return divided/ divining;
        }

         protected class Lecture
        {
            public string Code;
            public string Name;
            private int _akts;
            public int Akts
            {
                get
                {
                    return _akts;
                }
                set
                {
                    if (value > 0)
                        _akts = value;
                    else
                        Console.WriteLine("Wrong Akts Value!");
                }
            }
            private double _note;
             public double Note
            {
                get
                {
                    return _note;
                }
                set
                {
                    if (value > -1 && value < 101)
                        _note = value;
                    else
                        Console.WriteLine("Wrong Akts Value!");
                }
            }
        }

    }
}
