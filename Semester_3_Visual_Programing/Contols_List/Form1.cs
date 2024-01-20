using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        bool i = true;
        bool k = false;
        private void start23(bool lokum)
        {
            Liste.Items.Clear();
            foreach (Control c in Controls)
            {
                if (c.Visible)
                {
                    string p = c.Name + " - ( " + c.Location.X + " , " + c.Location.Y + " ) ";
                    Liste.Items.Add(p);
                }
                if (lokum)
                    checkedListBox1.Items.Add(c.Name);
            }
        }
        public Form1()
        {
            InitializeComponent(); 
        } 
        private void Button_Click(object sender, EventArgs e)
        {
            i = i ? false : true;
            k = true;
            Liste.Items.Clear();
            foreach (Control c in Controls)
            {
                if (c.Visible)
                {
                    string p = c.Name + " - ( " + c.Location.X + " , " + c.Location.Y + " ) - ( " + (c.Location.X + (c.Size.Width) / 2) + " , " + (c.Location.Y + (c.Size.Height) / 2) + " ) ";
                    Liste.Items.Add(p);
                }
            }
                this.BackColor = i ? Color.AliceBlue: Color.GreenYellow;

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            start23(true);
            Form1_SizeChanged(sender, e);
        }
        private void fake_button_click()
        {
            Liste.Items.Clear();
            foreach (Control c in Controls)
            {
                if (c.Visible)
                {
                    string p = c.Name + " - ( " + c.Location.X + " , " + c.Location.Y + " ) - ( " + (c.Location.X + (c.Size.Width) / 2) + " , " + (c.Location.Y + (c.Size.Height) / 2) + " ) ";
                    Liste.Items.Add(p);
                }
            }
        }
        private void checkedListBox1_SelectedValueChanged(object sender, EventArgs e)
        {
            foreach (Control c in Controls)
            {
                if (checkedListBox1.SelectedItem == c.Name)
                    c.Visible = !checkedListBox1.GetItemChecked(checkedListBox1.SelectedIndex);
            }
            if (k)
            {
                fake_button_click();
            }
            else
            {
                start23(false);
            }
        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            Graphics g = this.CreateGraphics();
            Double startingPoint = (this.Width / 2) - (g.MeasureString(this.Text.Trim(), this.Font).Width / 2);
            Double widthOfASpace = g.MeasureString(" ", this.Font).Width;
            String tmp = " ";
            Double tmpWidth = 0;

            while ((tmpWidth + widthOfASpace) < startingPoint)
            {
                tmp += " ";
                tmpWidth += widthOfASpace;
            }

            this.Text = tmp + this.Text.Trim();
            
        }
    }
}
