using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleStudentInformationSystem
{
    internal class UndergraduateStudent : Student
    {
        public override void Print()
        {
            StartOfPrint();
            LecturePrint();
        }
    }
    internal class GraduateStudent : Student
    {
        private string _undergraduateSchoolName;
        private string _undergraduateDepartmanName;
        public GraduateStudent(string undergraduateSchoolName, string undergraduateDepartmanName)
        {
            _undergraduateSchoolName = undergraduateSchoolName;
            _undergraduateDepartmanName = undergraduateDepartmanName;

        }
        public override void Print()
        {
            StartOfPrint();
            Console.WriteLine("\t Undergraduate Information");
            Console.WriteLine("\t\t{0,30}; {1,10}", this._undergraduateSchoolName, this._undergraduateDepartmanName);
            LecturePrint();

        }
    }
    internal class PhdStudent : Student
    {
        private string _undergraduateSchoolName;
        private string _undergraduateDepartmanName;
        private string _graduateSchoolName;
        private string _graduateDepartmanName;
        public override void Print()
        {
            StartOfPrint();
            Console.WriteLine("\t Undergraduate Information");
            Console.WriteLine("\t\t{0,30}; {1,10}", this._undergraduateSchoolName, this._undergraduateDepartmanName);
            Console.WriteLine("\t Graduate Information");
            Console.WriteLine("\t\t{0,30}; {1,10}", this._graduateSchoolName, this._graduateDepartmanName);
            LecturePrint();
        }
        public PhdStudent(string undergraduateSchoolName, string undergraduateDepartmanName, string graduateSchoolName, string graduateDepartmanName)
        {
            _undergraduateSchoolName = undergraduateSchoolName;
            _undergraduateDepartmanName = undergraduateDepartmanName;
            _graduateSchoolName = graduateSchoolName;
            _graduateDepartmanName = graduateDepartmanName;
        }
    }
}
