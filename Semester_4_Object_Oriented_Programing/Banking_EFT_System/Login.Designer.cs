namespace _2017280030_OOP_Final
{
    partial class Login
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
            System.Windows.Forms.Label UserIdLabel;
            System.Windows.Forms.Label PasswordLabel;
            this.UserIdText = new System.Windows.Forms.TextBox();
            this.PasswordText = new System.Windows.Forms.TextBox();
            this.EnterButton = new System.Windows.Forms.Button();
            this.ExitButton = new System.Windows.Forms.Button();
            UserIdLabel = new System.Windows.Forms.Label();
            PasswordLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // UserIdLabel
            // 
            UserIdLabel.AutoSize = true;
            UserIdLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            UserIdLabel.ForeColor = System.Drawing.Color.Purple;
            UserIdLabel.Location = new System.Drawing.Point(96, 61);
            UserIdLabel.Name = "UserIdLabel";
            UserIdLabel.Size = new System.Drawing.Size(76, 20);
            UserIdLabel.TabIndex = 0;
            UserIdLabel.Text = "User ID:";
            // 
            // PasswordLabel
            // 
            PasswordLabel.AutoSize = true;
            PasswordLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            PasswordLabel.ForeColor = System.Drawing.Color.Purple;
            PasswordLabel.Location = new System.Drawing.Point(81, 131);
            PasswordLabel.Name = "PasswordLabel";
            PasswordLabel.Size = new System.Drawing.Size(91, 20);
            PasswordLabel.TabIndex = 1;
            PasswordLabel.Text = "Password:";
            // 
            // UserIdText
            // 
            this.UserIdText.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.UserIdText.Location = new System.Drawing.Point(178, 61);
            this.UserIdText.MaxLength = 6;
            this.UserIdText.Name = "UserIdText";
            this.UserIdText.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.UserIdText.Size = new System.Drawing.Size(100, 20);
            this.UserIdText.TabIndex = 2;
            this.UserIdText.TextChanged += new System.EventHandler(this.UserIdText_TextChanged);
            // 
            // PasswordText
            // 
            this.PasswordText.Location = new System.Drawing.Point(178, 131);
            this.PasswordText.MaxLength = 8;
            this.PasswordText.Name = "PasswordText";
            this.PasswordText.PasswordChar = '*';
            this.PasswordText.Size = new System.Drawing.Size(100, 20);
            this.PasswordText.TabIndex = 3;
            this.PasswordText.UseSystemPasswordChar = true;
            this.PasswordText.TextChanged += new System.EventHandler(this.PasswordText_TextChanged);
            // 
            // EnterButton
            // 
            this.EnterButton.BackColor = System.Drawing.Color.DarkGray;
            this.EnterButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.EnterButton.Location = new System.Drawing.Point(177, 208);
            this.EnterButton.Name = "EnterButton";
            this.EnterButton.Size = new System.Drawing.Size(101, 41);
            this.EnterButton.TabIndex = 4;
            this.EnterButton.Text = "Enter";
            this.EnterButton.UseVisualStyleBackColor = false;
            this.EnterButton.Click += new System.EventHandler(this.EnterButton_Click);
            // 
            // ExitButton
            // 
            this.ExitButton.BackColor = System.Drawing.Color.DarkGray;
            this.ExitButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ExitButton.ForeColor = System.Drawing.Color.Red;
            this.ExitButton.Location = new System.Drawing.Point(371, 208);
            this.ExitButton.Name = "ExitButton";
            this.ExitButton.Size = new System.Drawing.Size(101, 41);
            this.ExitButton.TabIndex = 5;
            this.ExitButton.Text = "Exit";
            this.ExitButton.UseVisualStyleBackColor = false;
            this.ExitButton.Click += new System.EventHandler(this.ExitButton_Click);
            // 
            // Login
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(484, 261);
            this.Controls.Add(this.ExitButton);
            this.Controls.Add(this.EnterButton);
            this.Controls.Add(this.PasswordText);
            this.Controls.Add(this.UserIdText);
            this.Controls.Add(PasswordLabel);
            this.Controls.Add(UserIdLabel);
            this.MaximumSize = new System.Drawing.Size(500, 300);
            this.MinimumSize = new System.Drawing.Size(500, 300);
            this.Name = "Login";
            this.Text = "Login";
            this.Load += new System.EventHandler(this.Login_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox UserIdText;
        private System.Windows.Forms.TextBox PasswordText;
        private System.Windows.Forms.Button EnterButton;
        private System.Windows.Forms.Button ExitButton;
    }
}