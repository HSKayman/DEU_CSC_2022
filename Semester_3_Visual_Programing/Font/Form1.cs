using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HomeWork1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            
        }
        int OldSize = 14;
        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {

            if (Convert.ToInt16(numericUpDown1.Value) >= 16 &&OldSize< Convert.ToInt16(numericUpDown1.Value))
                MessageBox.Show("Text may not fit on the screen", "Text Problem!");

            label1.Font = new Font(label1.Font.FontFamily, Convert.ToInt16(numericUpDown1.Value), label1.Font.Style);
            OldSize = Convert.ToInt16(numericUpDown1.Value);
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            label1.ForeColor = Color.Red;
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            label1.ForeColor = Color.Green;
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            label1.ForeColor = Color.Blue;
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            label1.Font = new Font(label1.Font, label1.Font.Style ^ FontStyle.Bold);
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            label1.Font = new Font(label1.Font, label1.Font.Style ^ FontStyle.Italic);
        }

        private void Underline_CheckedChanged(object sender, EventArgs e)
        {
            label1.Font = new Font(label1.Font, label1.Font.Style ^ FontStyle.Underline);
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            label1.Font = new Font(label1.Font, label1.Font.Style ^ FontStyle.Strikeout);
        }

        private void label1_MouseHover(object sender, EventArgs e)
        {
            label1.Font = new Font(label1.Font.FontFamily, Convert.ToInt16(numericUpDown1.Value)+5, label1.Font.Style);
        }

        private void label1_MouseLeave(object sender, EventArgs e)
        {
            label1.Font = new Font(label1.Font.FontFamily, Convert.ToInt16(numericUpDown1.Value) , label1.Font.Style);
        }
    }
}
