using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HomeWorkIII
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            panel1.Visible = true;

        }

        private void translateToolStripMenuItem_Click(object sender, EventArgs e)
        {
            panel1.Visible = false;
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            Application.Exit();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            panel1.Visible = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label2.Text = "";
            foreach (char i in textBox1.Text)
            {
                if (i == 'a')
                    label2.Text += Convert.ToChar(10241).ToString();
                else if (i == 'b')
                    label2.Text += Convert.ToChar(10243).ToString();
                else if (i == 'c')
                    label2.Text += Convert.ToChar(10249).ToString();
                else if (i == 'd')
                    label2.Text += Convert.ToChar(10265).ToString();
                else if (i == 'e')
                    label2.Text += Convert.ToChar(10257).ToString();
                else if (i == 'f')
                    label2.Text += Convert.ToChar(10251).ToString();
                else if (i == 'g')
                    label2.Text += Convert.ToChar(10267).ToString();
                else if (i == 'h')
                    label2.Text += Convert.ToChar(10259).ToString();
                else if (i == 'i')
                    label2.Text += Convert.ToChar(10250).ToString();
                else if (i == 'j')
                    label2.Text += Convert.ToChar(10266).ToString();
                else if (i == 'k')
                    label2.Text += Convert.ToChar(10245).ToString();
                else if (i == 'l')
                    label2.Text += Convert.ToChar(10247).ToString();
                else if (i == 'm')
                    label2.Text += Convert.ToChar(10253).ToString();
                else if (i == 'n')
                    label2.Text += Convert.ToChar(10269).ToString();
                else if (i == 'o')
                    label2.Text += Convert.ToChar(10261).ToString();
                else if (i == 'p')
                    label2.Text += Convert.ToChar(10255).ToString();
                else if (i == 'q')
                    label2.Text += Convert.ToChar(10271).ToString();
                else if (i == 'r')
                    label2.Text += Convert.ToChar(10263).ToString();
                else if (i == 's')
                    label2.Text += Convert.ToChar(10254).ToString();
                else if (i == 't')
                    label2.Text += Convert.ToChar(10270).ToString();
                else if (i == 'u')
                    label2.Text += Convert.ToChar(10277).ToString();
                else if (i == 'v')
                    label2.Text += Convert.ToChar(10279).ToString();
                else if (i == 'w')
                    label2.Text += Convert.ToChar(10298).ToString();
                else if (i == 'x')
                    label2.Text += Convert.ToChar(10285).ToString();
                else if (i == 'y')
                    label2.Text += Convert.ToChar(10301).ToString();
                else if (i == 'z')
                    label2.Text += Convert.ToChar(10293).ToString();
                else if (i == 'A')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10241).ToString();
                else if (i == 'B')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10243).ToString();
                else if (i == 'C')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10249).ToString();
                else if (i == 'D')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10265).ToString();
                else if (i == 'E')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10257).ToString();
                else if (i == 'F')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10251).ToString();
                else if (i == 'G')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10267).ToString();
                else if (i == 'H')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10259).ToString();
                else if (i == 'I')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10250).ToString();
                else if (i == 'J')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10266).ToString();
                else if (i == 'K')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10245).ToString();
                else if (i == 'L')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10247).ToString();
                else if (i == 'M')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10253).ToString();
                else if (i == 'N')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10269).ToString();
                else if (i == 'O')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10261).ToString();
                else if (i == 'P')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10255).ToString();
                else if (i == 'Q')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10271).ToString();
                else if (i == 'R')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10263).ToString();
                else if (i == 'S')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10254).ToString();
                else if (i == 'T')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10270).ToString();
                else if (i == 'U')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10277).ToString();
                else if (i == 'V')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10279).ToString();
                else if (i == 'W')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10298).ToString();
                else if (i == 'X')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10285).ToString();
                else if (i == 'Y')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10301).ToString();
                else if (i == 'Z')
                    label2.Text += Convert.ToChar(10272).ToString() + Convert.ToChar(10293).ToString();
                else if (i == ',')
                    label2.Text += Convert.ToChar(10242).ToString();
                else if (i == ';')
                    label2.Text += Convert.ToChar(10246).ToString();
                else if (i == ':')
                    label2.Text += Convert.ToChar(10258).ToString();
                else if (i == '.')
                    label2.Text += Convert.ToChar(10290).ToString();
                else if (i == '!')
                    label2.Text += Convert.ToChar(10262).ToString();
                else if (i == '(')
                    label2.Text += Convert.ToChar(10294).ToString();
                else if (i == ')')
                    label2.Text += Convert.ToChar(10294).ToString();
                else if (i == '“')
                    label2.Text += Convert.ToChar(10278).ToString();
                else if (i == '”')
                    label2.Text += Convert.ToChar(10292).ToString();
                else if (i == '?')
                    label2.Text += Convert.ToChar(10278).ToString();
                else if (i == '/')
                    label2.Text += Convert.ToChar(10252).ToString();
                else if (i == '#')
                    label2.Text += Convert.ToChar(10300).ToString();
                else if (i == '\'')
                    label2.Text += Convert.ToChar(10244).ToString();
                else if (i == '…')
                    label2.Text += Convert.ToChar(10290).ToString() + Convert.ToChar(10290).ToString() + Convert.ToChar(10290).ToString();
                else if (i == '’')
                    label2.Text += Convert.ToChar(10244).ToString();
                else if (i == '-')
                    label2.Text += Convert.ToChar(10276).ToString() + Convert.ToChar(10276).ToString();
                else if (i == '1')
                    label2.Text += Convert.ToChar(10300).ToString() + Convert.ToChar(10241).ToString();
                else if (i == '2')
                    label2.Text += Convert.ToChar(10300).ToString() + Convert.ToChar(10243).ToString();
                else if (i == '3')
                    label2.Text += Convert.ToChar(10300).ToString() + Convert.ToChar(10249).ToString();
                else if (i == '4')
                    label2.Text += Convert.ToChar(10300).ToString() + Convert.ToChar(10265).ToString();
                else if (i == '5')
                    label2.Text += Convert.ToChar(10300).ToString() + Convert.ToChar(10257).ToString();
                else if (i == '6')
                    label2.Text += Convert.ToChar(10300).ToString() + Convert.ToChar(10251).ToString();
                else if (i == '7')
                    label2.Text += Convert.ToChar(10300).ToString() + Convert.ToChar(10267).ToString();
                else if (i == '8')
                    label2.Text += Convert.ToChar(10300).ToString() + Convert.ToChar(10259).ToString();
                else if (i == '9')
                    label2.Text += Convert.ToChar(10300).ToString() + Convert.ToChar(10250).ToString();
                else if (i == '0')
                    label2.Text += Convert.ToChar(10300).ToString() + Convert.ToChar(10266).ToString();
                else if (i == Convert.ToChar(32))
                    label2.Text += Convert.ToChar(32);
                else
                {
                    string x = "UNRECOGNIZED CHARACTER IS TAGET ->(" + i.ToString() +")";
                    MessageBox.Show(x);
                    label2.Text = "";
                }
                textBox1.Text = "";
            }
        }
    }
}
