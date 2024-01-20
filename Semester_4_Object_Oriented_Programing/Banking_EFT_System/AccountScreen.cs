using System;
using System.Windows.Forms;

namespace _2017280030_OOP_Final
{
    public partial class AccountScreen : Form
    {
        readonly BankAccount client;
        public AccountScreen(string accountNumber)
        {
            client =    AccountHolders.FindClient(accountNumber, "Account Number");
            InitializeComponent();
        }
        int Cronometre=300;
        private void AccountScreen_Load(object sender, EventArgs e)
        {
            try
            {
                Timer.Enabled = true;
                CurrencyInfo.Text = "Current savings in your accounts:\n\n" + client.GetBalance();
                NameLabel.Text = client.GetName();
                foreach (string otherName in AccountHolders.OtherName(client.GetName()))
                    PersonComboBox.Items.Add(otherName);
                ChoosenIBANComboBox.Items.Clear();
                foreach (string iban in client.GetIbans())
                    ChoosenIBANComboBox.Items.Add(iban);

                if (ChoosenIBANComboBox.Items.Count <= 0)
                {
                    throw new Error("Your Account has  not got a Account");
                }
                if (PersonComboBox.Items.Count <= 0)
                {
                    throw new Error("I'm sorry this bank has got a only member. He is you :)");
                }
            }
            catch (Exception exception)
            {
                MessageBox.Show(exception.Message, ":(", MessageBoxButtons.OK);
            }
        }
        private void PersonComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                IBANComboBox.Items.Clear();
                IBANComboBox.SelectedIndex = -1;
                BankAccount choosen = AccountHolders.FindClient(PersonComboBox.SelectedItem.ToString(), "Name");
                if (choosen == null)
                {
                    throw new Error("Your chosen Person is gone to another bank.");
                }
                foreach (string iban in choosen.GetIbans())
                    IBANComboBox.Items.Add(iban);
            }catch(Exception exception)
            {
                MessageBox.Show(exception.Message, ":(", MessageBoxButtons.OK);
            }
        }
        private void ApproveEftButton_Click(object sender, EventArgs e)
        {
            try
            {
                if (ChoosenIBANComboBox.SelectedIndex != -1 && IBANComboBox.SelectedIndex != -1 && PersonComboBox.SelectedIndex != -1 && Convert.ToDouble(MoneyBox.Text) != 0.00)
            {
               
                    client.TransferMoney(ChoosenIBANComboBox.Text, PersonComboBox.SelectedItem.ToString(), IBANComboBox.SelectedItem.ToString(), MoneyBox.Text.ToString());
                    MessageBox.Show("Great! EFT operation succeeded.","Sucess",MessageBoxButtons.OK);
                    CurrencyInfo.Text = "Current savings in your accounts:\n\n" + client.GetBalance();
                }
                
            }
            catch (Exception exception)
            {
                if (String.Compare(exception.Message, "Dedect Problem For File Operation That Process is invalid.") == 0)
                {
                    FileOperations.CreateDefaultClient("normal");
                    FileOperations.CreatePersonalizedFile("normal");
                    FileOperations.CreateDefaultAuth("normal");
                }
                MessageBox.Show(exception.Message, "Problem", MessageBoxButtons.OK);
            }
        }
        private void ExitButton_Click(object sender, EventArgs e)
        {
            this.Close();
            Program.login.Show();
        }
        private void Timer_Tick(object sender, EventArgs e)
        {
            Cronometre -= 1;
            if (Cronometre <= 0)
            {
                this.Close();
                Program.login.Show();
            }
            else if (Cronometre <= 60)
            {
                AlertMessageLabel.Text = "SECURITY WARNING!\n\nThis screen is inactive for the last 4 minutes.\n" +
                    "You will be automatically logged off\nfrom the system in 60 seconds...!";
            }
        }
        private void AccountScreen_MouseMove(object sender, MouseEventArgs e)
        {
            Cronometre = 300;
            AlertMessageLabel.Text = "";
        }
    }
}
