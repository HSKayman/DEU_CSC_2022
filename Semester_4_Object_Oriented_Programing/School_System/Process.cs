using System;
using System.Threading;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleStudentInformationSystem
{
    public class Process
    {
        
        static private List<Student> students = new List<Student>();
        static private void AddDefaultInfo(Student student)
        {
            Console.WriteLine("Student Id: ");
            student.Id = Console.ReadLine();
            Console.WriteLine("Student Name And Surname: ");
            student.NameSurname = Console.ReadLine();
            Console.WriteLine("Student Departman: ");
            student.DepartmanName = Console.ReadLine();
            Console.Clear();
            while (true)
            {
                Console.WriteLine("Lecture Name: ");
                string name = Console.ReadLine();
                Console.WriteLine("Lecture Id: ");
                string code = Console.ReadLine();
                Console.WriteLine("Mark Of Student");
                double mark = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine("Do You Know Akts Of Lecture[Y/(other button)]:");
                if (String.Compare(Console.ReadLine(), "Y") == 0)
                {
                    Console.WriteLine("Akts Of Lecture: ");
                    int akts = Convert.ToInt32(Console.ReadLine());
                    student.LectureAdd(code, name, mark, akts);
                }
                else
                {
                    student.LectureAdd(code, name, mark);
                }
                Console.WriteLine("Is There Any Other Lesson The Student Has Taken[Y/(other button)]?");
                if (String.Compare(Console.ReadLine(), "Y") == 0)
                {
                    Console.Clear();
                    continue;
                }
                else
                {
                    Console.Clear();
                    break;
                }

            }
            students.Add(student);
        }
        
        
        static public void StudentAdd()
        {
            while (true)
            {
                int chooseP;
                Console.WriteLine("1-Add Undergraduate Student");
                Console.WriteLine("2-Add Graduate Student");
                Console.WriteLine("3-Add Phd Student");
                Console.WriteLine("Choose :");
                chooseP = Convert.ToInt32(Console.ReadLine());
                Console.Clear();
                if (chooseP == 1)
                {
                    UndergraduateStudent undergraduateStudent = new UndergraduateStudent();
                    AddDefaultInfo(undergraduateStudent);
                }
                else if (chooseP == 2)
                {
                    Console.WriteLine("Student's Undergraduate School Name:");
                    string undergraduateSchoolName = Console.ReadLine();
                    Console.WriteLine("Student's Undergraduate Departman Name:");
                    string undergraduateDepartmanName = Console.ReadLine();
                    GraduateStudent graduateStudent = new GraduateStudent(undergraduateSchoolName, undergraduateDepartmanName);
                    AddDefaultInfo(graduateStudent);
                }
                else if (chooseP == 3)
                {
                    Console.WriteLine("Student's Undergraduate School Name:");
                    string undergraduateSchoolName = Console.ReadLine();
                    Console.WriteLine("Student's Undergraduate Departman Name:");
                    string undergraduateDepartmanName = Console.ReadLine();
                    Console.WriteLine("Student's Graduate School Name:");
                    string graduateSchoolName = Console.ReadLine();
                    Console.WriteLine("Student's Graduate Departman Name:");
                    string graduateDepartmanName = Console.ReadLine();
                    PhdStudent graduateStudent = new PhdStudent(undergraduateSchoolName, undergraduateDepartmanName, graduateDepartmanName, graduateSchoolName);
                    AddDefaultInfo(graduateStudent);
                }
                else
                {
                    Console.WriteLine("Wrong Choice!");
                    Console.ReadKey();
                    Console.Clear();
                    continue;
                }
                Console.Clear();
            }
        }
        static public void StudentPrint()
        { 
            foreach (Student student in students)
            {
                Console.WriteLine(student.GetType().Name);
                student.Print();
            }
        }
        public static void ManualInput(string id,string nameSurname,string departmanName,params Temp[] lectures)
        {
            UndergraduateStudent undergraduateStudent = new UndergraduateStudent();
            undergraduateStudent.Id = id;
            undergraduateStudent.NameSurname = nameSurname;
            undergraduateStudent.DepartmanName = departmanName;
            foreach(Temp lecture in lectures)
            {
                undergraduateStudent.LectureAdd(lecture.code, lecture.name, lecture.mark, lecture.akts);
            }
            students.Add(undergraduateStudent);
        }
        public static void ManualInput(string id, string nameSurname, string departmanName,string undergraduateSchoolName,string undergraduateDepartmanName,params Temp[]lectures)
        {
            GraduateStudent graduateStudent = new GraduateStudent(undergraduateSchoolName,undergraduateDepartmanName);
            graduateStudent.Id = id;
            graduateStudent.NameSurname = nameSurname;
            graduateStudent.DepartmanName = departmanName;
            foreach (Temp lecture in lectures)
            {
                graduateStudent.LectureAdd(lecture.code, lecture.name, lecture.mark, lecture.akts);
            }
            students.Add(graduateStudent);
        }
        public static void ManualInput(string id, string nameSurname, string departmanName, string undergraduateSchoolName, string undergraduateDepartmanName,
                                        string graduateSchoolName, string graduateDepartmanName,params Temp[]lectures)
        {
            PhdStudent phdStudent = new PhdStudent(undergraduateSchoolName, undergraduateDepartmanName,graduateSchoolName, graduateDepartmanName);
            phdStudent.Id = id;
            phdStudent.NameSurname = nameSurname;
            phdStudent.DepartmanName = departmanName;
            foreach (Temp lecture in lectures)
            {
                phdStudent.LectureAdd(lecture.code, lecture.name, lecture.mark, lecture.akts);
            }
            students.Add(phdStudent);
        }
    }
    public class Temp//Bu Kutuphaneye sahip yazilimcinin ders bilgilerini aktarmasi icin var.Lecturenin mainden ulasilmasini istemiyorum.
    {
        public string code;
        public string name;
        public int akts;
        public double mark;
    }
}
