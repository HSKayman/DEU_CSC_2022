using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SimpleStudentInformationSystem;

namespace Main
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("1-Add Student");
                Console.WriteLine("2-Show Students");
                Console.WriteLine("3-Run Embedded Information");
                Console.WriteLine("4-Exit");
                Console.WriteLine("Choose : ");
                int chooseP = Convert.ToInt32(Console.ReadLine());
                Console.Clear();
                if (chooseP == 1) {
                    Process.StudentAdd();
                }
                else if (chooseP == 2)
                {
                    Process.StudentPrint();
                }
                else if (chooseP == 3)
                {

                    Process.ManualInput("2008291014", "HAMIYET MANDIRALI", "MATEMATIK", 
                        new Temp { code = "MAT101", name = "Matematik1", akts = 6, mark = 62.0 },
                        new Temp { code = "MAT107", name = "Soyut Matematik", akts = 6, mark = 60.0 },
                        new Temp { code = "FSH333", name = "Hayat Bilgisi", akts = 8, mark = 60.0 });

                    Process.ManualInput("2017280030", "SUCA KAYMAN", "BILGISAYAR BILIMLERI",
                        new Temp { code = "MAT101", name = "Matematik1", akts =5, mark = 80.0 },
                        new Temp { code = "MAT107", name = "Soyut Matematik", akts = 4, mark = 74.0 },
                        new Temp { code = "FSH333", name = "Hayat Bilgisi", akts = 5, mark = 60.0 });

                    Process.ManualInput("2008291022", "TANER INER", "ASTROFIZIK",
                        new Temp { code = "MAT101", name = "Matematik1", akts = 6, mark = 95.0 },
                        new Temp { code = "MAT107", name = "Soyut Matematik", akts = 6, mark = 90.0 },
                        new Temp { code = "FSH333", name = "Hayat Bilgisi", akts = 8, mark = 100.0 },
                        new Temp { code = "AST101", name = "Astrofizige giris", akts = 12, mark = 88.0 });

                    Process.ManualInput("2009291062", "ADIL KEMAL KURKER", "TARIH","ISTANBUL UNIVERSITESI", "TARIH",
                        new Temp { code = "TAR505", name = "Tatar Tarihi", akts = 18, mark = 79.0 },
                        new Temp { code = "MAT511", name = "Uzakdogu Halklari", akts = 18, mark = 100.0 }
                        );
                    Process.ManualInput("2010432000", "SENEM BILGIC", "BILGISAYAR BILIMLERI", "DOKUZ EYLUL UNIVERSITESI", "BILGISAYAR BILIMLERI",
                        new Temp { code = "CSC5001", name = "Fuzzy Data Analysis", akts = 8, mark = 78.0 },
                        new Temp { code = "CSC5019", name = "Software Engineering", akts = 8, mark = 40.0 },
                        new Temp { code = "MAT5101", name = "Applied Mathmeatics", akts = 9, mark = 83.0 }
                        );

                    Process.ManualInput("2009291030", "DOGAC SAZAN", "SPOR BILIMLERI", "EGE UNIVERSITESI", "BEDEN EGITIMI",
                        "UNIVERSITY OF BRITISH COLUMBIA","KINSESIOILOGY",
                        new Temp { code = "SPB603", name = "Rehabilitatif Spor", akts = 18, mark = 95.0 },
                        new Temp { code = "SPB630", name = "Software Engineering", akts = 6, mark = 100.0 }
                        );
                    Process.StudentPrint();
                }
                else if (chooseP == 4)
                {
                    break;
                }
                else
                {
                    Console.WriteLine("Wrong Choice!");
                    Console.ReadKey();
                    Console.Clear();
                    continue;
                }
            }
        }
    }
}
