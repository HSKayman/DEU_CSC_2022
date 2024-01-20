using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp12
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        Graphics g;
        Boolean mod = false, mod3 = false, mod2 = false;
        Point x2, y2,n;

        private void button1_Click(object sender, EventArgs e)
        {
            ColorDialog c = new ColorDialog();
            if (c.ShowDialog() == DialogResult.OK)
            {
                button1.BackColor = c.Color;
            }
        }

        private void panel1_MouseUp(object sender, MouseEventArgs e)
        {
            mod = false;
            mod2 = false;
            mod3 = false;
            if (checkBox1.Checked)
            {
                if (radioButton1.Checked)
                {
                    g.FillRectangle(new SolidBrush(button1.BackColor), e.X - Convert.ToInt32(textBox1.Text) / 2, e.Y - Convert.ToInt32(textBox1.Text) / 2, Convert.ToInt32(textBox1.Text), Convert.ToInt32(textBox1.Text));
                }
                else if (radioButton2.Checked)
                {
                    g.FillRectangle(new SolidBrush(button1.BackColor), e.X - Convert.ToInt32(textBox1.Text), e.Y - Convert.ToInt32(textBox1.Text) / 2, 2 * Convert.ToInt32(textBox1.Text), Convert.ToInt32(textBox1.Text));
                    
                }
                else if (radioButton3.Checked)
                {
                    g.FillPie(new SolidBrush(button1.BackColor), e.X - Convert.ToInt32(textBox1.Text) / 2, e.Y - Convert.ToInt32(textBox1.Text) / 2, Convert.ToInt32(textBox1.Text), Convert.ToInt32(textBox1.Text), 0, 360);
                }
            }
            if (checkBox2.Checked && radioButton4.Checked)
            {
                y2 = e.Location;
                g.DrawLine(new Pen(button1.BackColor, Convert.ToInt32(numericUpDown1.Value)), x2, y2);
            }
           
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.Text = "20";
            button1.BackColor = Color.Black;
            g = panel1.CreateGraphics();
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox2.Checked)
            {
                checkBox1.Checked = false;
                checkBox2.Checked = true;
            }
        }

        private void radioButton6_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton6.Checked)
            {
                numericUpDown1.Value = 5;
                numericUpDown1.Minimum = 5;
            }
            else
                numericUpDown1.Minimum = 1;
        }

        private void radioButton7_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton7.Checked)
            {
                numericUpDown1.Value = 5;
                numericUpDown1.Minimum = 5;
            }
            else
                numericUpDown1.Minimum = 1;
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                checkBox1.Checked = true;
                checkBox2.Checked = false;
            }
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            if (mod&&radioButton5.Checked&&checkBox2.Checked)
            {
                g.DrawLine(new Pen(button1.BackColor,Convert.ToInt32(numericUpDown1.Value)),n,e.Location);
                n = e.Location;
            }
            else if (radioButton6.Checked && mod3&&checkBox2.Checked&&mod3)
            {
                g.FillPie(new SolidBrush(button1.BackColor),e.X- Convert.ToInt32(numericUpDown1.Value)/2, e.Y- Convert.ToInt32(numericUpDown1.Value)/2, Convert.ToInt32(numericUpDown1.Value), Convert.ToInt32(numericUpDown1.Value), 0,360);
            }else if (radioButton7.Checked && checkBox2.Checked && mod2)
            {
                g.FillPie(new SolidBrush(panel1.BackColor), e.X - Convert.ToInt32(numericUpDown1.Value) / 2, e.Y - Convert.ToInt32(numericUpDown1.Value) / 2, Convert.ToInt32(numericUpDown1.Value), Convert.ToInt32(numericUpDown1.Value), 0, 360);

            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            g.Clear(panel1.BackColor);
        }
        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            if (checkBox2.Checked&&radioButton5.Checked)
            {
                mod = true;
                n = e.Location;
            }else if (checkBox2.Checked && radioButton4.Checked)
            {
                x2 = e.Location;
            }else if (checkBox2.Checked && radioButton6.Checked)
            {
                mod3 = true;
            }
            else if (checkBox2.Checked && radioButton7.Checked)
            {
                mod2 = true;
            }
        }
    }
}
