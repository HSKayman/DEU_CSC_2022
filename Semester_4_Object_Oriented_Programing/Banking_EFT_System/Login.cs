using System;
using System.IO;
using System.Windows.Forms;

namespace _2017280030_OOP_Final
{
    public partial class Login : Form
    {
        private BankAccount client;
        public Login()
        {
            InitializeComponent();
        }
        private void Login_Load(object sender, EventArgs e)
        {
            try
            {
                FileOperations.CreateDefaultClient("normal");
                FileOperations.CreatePersonalizedFile("normal");
                FileOperations.CreateDefaultAuth("normal");
            }catch(Exception exception)
            {
                MessageBox.Show(exception.Message,"Alert",MessageBoxButtons.OK);
                this.Close();
            }
            try
            {
                (new PersonalClient()).Read();
            }
            catch (Exception exception)
            {
                MessageBox.Show(exception.Message, "Alert", MessageBoxButtons.OK);
            }
        }
        private void PasswordText_TextChanged(object sender, EventArgs e)
        {
            if (!(String.IsNullOrEmpty(PasswordText.Text)))
            {
                if (!(char.IsLetterOrDigit(PasswordText.Text[PasswordText.Text.Length - 1])))
                {
                    MessageBox.Show("Please Enter Number or Letter!", "Notice", MessageBoxButtons.OK);
                    string newPassword = "";
                    for (int i = 0; i < PasswordText.Text.Length - 1; ++i)
                        newPassword += PasswordText.Text[i];
                    PasswordText.Text = newPassword;
                    PasswordText.Select(PasswordText.Text.Length, 0);
                }
            }
        }
        private void UserIdText_TextChanged(object sender, EventArgs e)
        {
            if (!(String.IsNullOrEmpty(UserIdText.Text)))
            {
                if (!(Char.IsDigit(UserIdText.Text[UserIdText.Text.Length - 1]))){
                    MessageBox.Show("Please Enter The Number!", "Notice", MessageBoxButtons.OK);
                    string newUserId = "";
                    for (int i = 0; i < UserIdText.Text.Length - 1; ++i)
                        newUserId += UserIdText.Text[i];
                    UserIdText.Text = newUserId;
                    UserIdText.Select(UserIdText.Text.Length, 0);
                }
            }
        }
        private void ExitButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        private void EnterButton_Click(object sender, EventArgs e)
        {
            if ((UserIdText.Text.Length != 6 || PasswordText.Text.Length != 8))
            {
                MessageBox.Show("Account Number should be 6 character. Password should be 8 character, Please Try Again.", "Notice", MessageBoxButtons.OK);
                UserIdText.Clear();
                PasswordText.Clear();
            }
            else
            {
                if ((client = AccountHolders.FindClient(UserIdText.Text, "Account Number")) == null) {
                    MessageBox.Show("Account Number or Password is Incorrect, Please Try Again.", "Notice", MessageBoxButtons.OK);
                    PasswordText.Clear();
                }
                else 
                {
                    if (client.Check(PasswordText.Text) && client.IsLocked())
                    { 
                        AccountScreen accountScreen = new AccountScreen(UserIdText.Text);
                        this.Hide();
                        accountScreen.Show();
                        PasswordText.Clear();
                    }
                    else
                    {
                        Logger();
                        MessageBox.Show("Account Number or Password is Incorrect, Please Try Again.", "Notice", MessageBoxButtons.OK);
                        PasswordText.Clear();
                    }
                }
            }
            
        }
        private void Logger()
        {

            if (client == null)
            {
                return;
            }
            else
            {

                FileStream fileStream=null;
                if (!Directory.Exists(@"c:\\final"))
                {
                    Directory.CreateDirectory(@"c:\\final");
                }
                if (!File.Exists(@"c:\\final\\logger.txt"))
                {
                    fileStream = new FileStream(@"c:\\final\\logger.txt", FileMode.Create, FileAccess.Write);
                    StreamWriter streamWrite = new StreamWriter(fileStream);
                    streamWrite.WriteLine("{0},{1},{2}", UserIdText.Text, "1", DateTime.Now.ToString());
                    streamWrite.Close();
                    fileStream.Close();
                    return;
                }
                else
                {
                    try
                    {
                        fileStream = new FileStream(@"c:\\final\\logger.txt", FileMode.Open, FileAccess.Read);
                        StreamReader streamReader = new StreamReader(fileStream);
                        string[] lines = streamReader.ReadToEnd().Split('\n');
                        streamReader.Close();

                        if (lines == null)
                        {
                            fileStream.Close();
                            new Error("logger File is Empty.");
                        }
                        fileStream = new FileStream(@"c:\\final\\logger.txt", FileMode.Create, FileAccess.Write);
                        StreamWriter streamWrite = new StreamWriter(fileStream);
                        bool find = false;
                        foreach (string line in lines)
                        {
                            if (String.IsNullOrEmpty(line.Replace("\n", "").Replace("\r", "")))
                            {
                                continue;
                            }
                            string[] splitline = line.Replace("\n", "").Replace("\r", "").Split(',');
                            if (String.Compare(splitline[0], UserIdText.Text) == 0)
                            {
                                find = true;
                                if (DateTime.Now.Subtract(Convert.ToDateTime(splitline[2])).TotalMinutes <= 5)
                                {
                                    if (Convert.ToInt32(splitline[1]) + 1 >= 3)
                                    {
                                        client.Locked();
                                    }
                                    else
                                    {
                                        streamWrite.WriteLine("{0},{1},{2}", UserIdText.Text, Convert.ToInt32(splitline[1]) + 1, splitline[2]);
                                    }
                                }
                                else
                                {
                                    streamWrite.WriteLine("{0},{1},{2}", UserIdText.Text, "1", DateTime.Now.ToString());
                                }
                            }
                            else if (DateTime.Now.Subtract(Convert.ToDateTime(splitline[2])).TotalMinutes <= 5)
                            {
                                streamWrite.WriteLine("{0},{1},{2}", UserIdText.Text, lines[1], lines[2]);
                            }
                        }
                        if (!find)
                        {
                            streamWrite.WriteLine("{0},{1},{2}", UserIdText.Text, "1", DateTime.Now.ToString());
                        }
                        streamWrite.Close();
                        fileStream.Close();
                        return;
                    }
                    catch (Exception exception)
                    {
                        fileStream.Close();
                        fileStream = new FileStream(@"c:\\final\\logger.txt", FileMode.Create, FileAccess.Write);
                        StreamWriter streamWrite = new StreamWriter(fileStream);
                        streamWrite.WriteLine("{0},{1},{2}", UserIdText.Text, "1", DateTime.Now.ToString());
                        streamWrite.Close();
                        fileStream.Close();
                        MessageBox.Show("File Destoryed. But All is Well Error: "+exception.Message, "Problem", MessageBoxButtons.OK);
                        return;
                    }
                }
            }
            
        }
    }
}
