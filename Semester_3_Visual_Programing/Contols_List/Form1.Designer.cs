namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Button = new System.Windows.Forms.Button();
            this.Liste = new System.Windows.Forms.ListBox();
            this.List_II = new System.Windows.Forms.ListBox();
            this.Check = new System.Windows.Forms.CheckBox();
            this.Label = new System.Windows.Forms.Label();
            this.Link = new System.Windows.Forms.LinkLabel();
            this.Rich = new System.Windows.Forms.RichTextBox();
            this.Progress = new System.Windows.Forms.ProgressBar();
            this.Mesked = new System.Windows.Forms.MaskedTextBox();
            this.Radio = new System.Windows.Forms.RadioButton();
            this.Track = new System.Windows.Forms.TrackBar();
            this.checkedListBox1 = new System.Windows.Forms.CheckedListBox();
            ((System.ComponentModel.ISupportInitialize)(this.Track)).BeginInit();
            this.SuspendLayout();
            // 
            // Button
            // 
            this.Button.Location = new System.Drawing.Point(289, 10);
            this.Button.Name = "Button";
            this.Button.Size = new System.Drawing.Size(51, 420);
            this.Button.TabIndex = 0;
            this.Button.Text = "Bas";
            this.Button.UseVisualStyleBackColor = true;
            this.Button.Click += new System.EventHandler(this.Button_Click);
            // 
            // Liste
            // 
            this.Liste.FormattingEnabled = true;
            this.Liste.Location = new System.Drawing.Point(12, 10);
            this.Liste.Name = "Liste";
            this.Liste.Size = new System.Drawing.Size(254, 420);
            this.Liste.TabIndex = 1;
            // 
            // List_II
            // 
            this.List_II.FormattingEnabled = true;
            this.List_II.Location = new System.Drawing.Point(669, 13);
            this.List_II.Name = "List_II";
            this.List_II.Size = new System.Drawing.Size(120, 95);
            this.List_II.TabIndex = 2;
            // 
            // Check
            // 
            this.Check.AutoSize = true;
            this.Check.Location = new System.Drawing.Point(456, 70);
            this.Check.Name = "Check";
            this.Check.Size = new System.Drawing.Size(60, 17);
            this.Check.TabIndex = 3;
            this.Check.Text = "Isaretle";
            this.Check.UseVisualStyleBackColor = true;
            // 
            // Label
            // 
            this.Label.AutoSize = true;
            this.Label.Location = new System.Drawing.Point(382, 94);
            this.Label.Name = "Label";
            this.Label.Size = new System.Drawing.Size(25, 13);
            this.Label.TabIndex = 4;
            this.Label.Text = "Yaz";
            // 
            // Link
            // 
            this.Link.AccessibleName = "Link";
            this.Link.AutoSize = true;
            this.Link.Location = new System.Drawing.Point(454, 96);
            this.Link.Name = "Link";
            this.Link.Size = new System.Drawing.Size(49, 13);
            this.Link.TabIndex = 5;
            this.Link.TabStop = true;
            this.Link.Text = "Linke Git";
            // 
            // Rich
            // 
            this.Rich.Location = new System.Drawing.Point(563, 11);
            this.Rich.Name = "Rich";
            this.Rich.Size = new System.Drawing.Size(100, 96);
            this.Rich.TabIndex = 6;
            this.Rich.Text = "";
            // 
            // Progress
            // 
            this.Progress.Location = new System.Drawing.Point(457, 14);
            this.Progress.Name = "Progress";
            this.Progress.Size = new System.Drawing.Size(100, 23);
            this.Progress.TabIndex = 7;
            // 
            // Mesked
            // 
            this.Mesked.Location = new System.Drawing.Point(457, 43);
            this.Mesked.Name = "Mesked";
            this.Mesked.Size = new System.Drawing.Size(100, 20);
            this.Mesked.TabIndex = 8;
            // 
            // Radio
            // 
            this.Radio.AutoSize = true;
            this.Radio.Location = new System.Drawing.Point(354, 19);
            this.Radio.Name = "Radio";
            this.Radio.Size = new System.Drawing.Size(53, 17);
            this.Radio.TabIndex = 9;
            this.Radio.TabStop = true;
            this.Radio.Text = "Buton";
            this.Radio.UseVisualStyleBackColor = true;
            // 
            // Track
            // 
            this.Track.Location = new System.Drawing.Point(347, 43);
            this.Track.Name = "Track";
            this.Track.Size = new System.Drawing.Size(104, 45);
            this.Track.TabIndex = 10;
            // 
            // checkedListBox1
            // 
            this.checkedListBox1.FormattingEnabled = true;
            this.checkedListBox1.Location = new System.Drawing.Point(385, 141);
            this.checkedListBox1.Name = "checkedListBox1";
            this.checkedListBox1.Size = new System.Drawing.Size(404, 289);
            this.checkedListBox1.TabIndex = 11;
            this.checkedListBox1.SelectedValueChanged += new System.EventHandler(this.checkedListBox1_SelectedValueChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(818, 445);
            this.Controls.Add(this.checkedListBox1);
            this.Controls.Add(this.Track);
            this.Controls.Add(this.Radio);
            this.Controls.Add(this.Mesked);
            this.Controls.Add(this.Progress);
            this.Controls.Add(this.Rich);
            this.Controls.Add(this.Link);
            this.Controls.Add(this.Label);
            this.Controls.Add(this.Check);
            this.Controls.Add(this.List_II);
            this.Controls.Add(this.Liste);
            this.Controls.Add(this.Button);
            this.Name = "Form1";
            this.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Liste";
            this.TopMost = true;
            this.Load += new System.EventHandler(this.Form1_Load);
            this.SizeChanged += new System.EventHandler(this.Form1_SizeChanged);
            ((System.ComponentModel.ISupportInitialize)(this.Track)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Button;
        private System.Windows.Forms.ListBox Liste;
        private System.Windows.Forms.ListBox List_II;
        private System.Windows.Forms.CheckBox Check;
        private System.Windows.Forms.Label Label;
        private System.Windows.Forms.LinkLabel Link;
        private System.Windows.Forms.RichTextBox Rich;
        private System.Windows.Forms.ProgressBar Progress;
        private System.Windows.Forms.MaskedTextBox Mesked;
        private System.Windows.Forms.RadioButton Radio;
        private System.Windows.Forms.TrackBar Track;
        private System.Windows.Forms.CheckedListBox checkedListBox1;
    }
}

