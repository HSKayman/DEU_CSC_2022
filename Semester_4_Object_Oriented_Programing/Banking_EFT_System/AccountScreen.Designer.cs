namespace _2017280030_OOP_Final
{
    partial class AccountScreen
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
            this.components = new System.ComponentModel.Container();
            this.WelcomeLabel = new System.Windows.Forms.Label();
            this.NameLabel = new System.Windows.Forms.Label();
            this.CurrencyPanel = new System.Windows.Forms.Panel();
            this.CurrencyInfo = new System.Windows.Forms.Label();
            this.InformationI = new System.Windows.Forms.Label();
            this.PersonComboBox = new System.Windows.Forms.ComboBox();
            this.InformationII = new System.Windows.Forms.Label();
            this.IBANComboBox = new System.Windows.Forms.ComboBox();
            this.InformationIII = new System.Windows.Forms.Label();
            this.ChoosenIBANComboBox = new System.Windows.Forms.ComboBox();
            this.MoneyBox = new System.Windows.Forms.MaskedTextBox();
            this.InformationIV = new System.Windows.Forms.Label();
            this.AlertMessageLabel = new System.Windows.Forms.Label();
            this.ApproveEftButton = new System.Windows.Forms.Button();
            this.ExitButton = new System.Windows.Forms.Button();
            this.Timer = new System.Windows.Forms.Timer(this.components);
            this.CurrencyPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // WelcomeLabel
            // 
            this.WelcomeLabel.AutoSize = true;
            this.WelcomeLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 27.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.WelcomeLabel.Location = new System.Drawing.Point(13, 13);
            this.WelcomeLabel.Name = "WelcomeLabel";
            this.WelcomeLabel.Size = new System.Drawing.Size(180, 42);
            this.WelcomeLabel.TabIndex = 0;
            this.WelcomeLabel.Text = "Welcome";
            // 
            // NameLabel
            // 
            this.NameLabel.AutoSize = true;
            this.NameLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 27.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.NameLabel.Location = new System.Drawing.Point(212, 13);
            this.NameLabel.Name = "NameLabel";
            this.NameLabel.Size = new System.Drawing.Size(0, 42);
            this.NameLabel.TabIndex = 1;
            // 
            // CurrencyPanel
            // 
            this.CurrencyPanel.BackColor = System.Drawing.Color.LightGray;
            this.CurrencyPanel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.CurrencyPanel.Controls.Add(this.CurrencyInfo);
            this.CurrencyPanel.Location = new System.Drawing.Point(20, 76);
            this.CurrencyPanel.MaximumSize = new System.Drawing.Size(420, 460);
            this.CurrencyPanel.MinimumSize = new System.Drawing.Size(420, 460);
            this.CurrencyPanel.Name = "CurrencyPanel";
            this.CurrencyPanel.Size = new System.Drawing.Size(420, 460);
            this.CurrencyPanel.TabIndex = 2;
            // 
            // CurrencyInfo
            // 
            this.CurrencyInfo.AutoSize = true;
            this.CurrencyInfo.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CurrencyInfo.Location = new System.Drawing.Point(13, 18);
            this.CurrencyInfo.Name = "CurrencyInfo";
            this.CurrencyInfo.Size = new System.Drawing.Size(0, 16);
            this.CurrencyInfo.TabIndex = 0;
            // 
            // InformationI
            // 
            this.InformationI.AutoSize = true;
            this.InformationI.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.InformationI.Location = new System.Drawing.Point(502, 164);
            this.InformationI.Name = "InformationI";
            this.InformationI.Size = new System.Drawing.Size(220, 16);
            this.InformationI.TabIndex = 3;
            this.InformationI.Text = "Select the person to transfer money ";
            // 
            // PersonComboBox
            // 
            this.PersonComboBox.BackColor = System.Drawing.Color.LightGray;
            this.PersonComboBox.FormattingEnabled = true;
            this.PersonComboBox.Location = new System.Drawing.Point(505, 193);
            this.PersonComboBox.Name = "PersonComboBox";
            this.PersonComboBox.Size = new System.Drawing.Size(217, 21);
            this.PersonComboBox.TabIndex = 4;
            this.PersonComboBox.SelectedIndexChanged += new System.EventHandler(this.PersonComboBox_SelectedIndexChanged);
            // 
            // InformationII
            // 
            this.InformationII.AutoSize = true;
            this.InformationII.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.InformationII.Location = new System.Drawing.Point(760, 164);
            this.InformationII.Name = "InformationII";
            this.InformationII.Size = new System.Drawing.Size(268, 16);
            this.InformationII.TabIndex = 5;
            this.InformationII.Text = "Select the person\'s IBAN number to transfer ";
            // 
            // IBANComboBox
            // 
            this.IBANComboBox.BackColor = System.Drawing.Color.LightGray;
            this.IBANComboBox.FormattingEnabled = true;
            this.IBANComboBox.Location = new System.Drawing.Point(763, 193);
            this.IBANComboBox.Name = "IBANComboBox";
            this.IBANComboBox.Size = new System.Drawing.Size(265, 21);
            this.IBANComboBox.TabIndex = 6;
            // 
            // InformationIII
            // 
            this.InformationIII.AutoSize = true;
            this.InformationIII.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.InformationIII.Location = new System.Drawing.Point(502, 447);
            this.InformationIII.Name = "InformationIII";
            this.InformationIII.Size = new System.Drawing.Size(279, 16);
            this.InformationIII.TabIndex = 7;
            this.InformationIII.Text = "From your which account? Choose Your IBAN ";
            // 
            // ChoosenIBANComboBox
            // 
            this.ChoosenIBANComboBox.BackColor = System.Drawing.Color.LightGray;
            this.ChoosenIBANComboBox.FormattingEnabled = true;
            this.ChoosenIBANComboBox.Location = new System.Drawing.Point(505, 481);
            this.ChoosenIBANComboBox.Name = "ChoosenIBANComboBox";
            this.ChoosenIBANComboBox.Size = new System.Drawing.Size(276, 21);
            this.ChoosenIBANComboBox.TabIndex = 8;
            // 
            // MoneyBox
            // 
            this.MoneyBox.BackColor = System.Drawing.Color.LightGray;
            this.MoneyBox.Location = new System.Drawing.Point(846, 482);
            this.MoneyBox.Mask = "00000.00";
            this.MoneyBox.Name = "MoneyBox";
            this.MoneyBox.Size = new System.Drawing.Size(59, 20);
            this.MoneyBox.TabIndex = 9;
            // 
            // InformationIV
            // 
            this.InformationIV.AutoSize = true;
            this.InformationIV.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Italic | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.InformationIV.ForeColor = System.Drawing.Color.DarkRed;
            this.InformationIV.Location = new System.Drawing.Point(843, 447);
            this.InformationIV.Name = "InformationIV";
            this.InformationIV.Size = new System.Drawing.Size(281, 16);
            this.InformationIV.TabIndex = 10;
            this.InformationIV.Text = "Enter the amount of money you want to transfer";
            // 
            // AlertMessageLabel
            // 
            this.AlertMessageLabel.AutoSize = true;
            this.AlertMessageLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, ((System.Drawing.FontStyle)(((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic) 
                | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AlertMessageLabel.ForeColor = System.Drawing.Color.DarkRed;
            this.AlertMessageLabel.Location = new System.Drawing.Point(32, 539);
            this.AlertMessageLabel.Name = "AlertMessageLabel";
            this.AlertMessageLabel.Size = new System.Drawing.Size(0, 29);
            this.AlertMessageLabel.TabIndex = 11;
            // 
            // ApproveEftButton
            // 
            this.ApproveEftButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ApproveEftButton.Location = new System.Drawing.Point(660, 572);
            this.ApproveEftButton.Name = "ApproveEftButton";
            this.ApproveEftButton.Size = new System.Drawing.Size(121, 43);
            this.ApproveEftButton.TabIndex = 12;
            this.ApproveEftButton.Text = "Approve EFT";
            this.ApproveEftButton.UseVisualStyleBackColor = true;
            this.ApproveEftButton.Click += new System.EventHandler(this.ApproveEftButton_Click);
            // 
            // ExitButton
            // 
            this.ExitButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ExitButton.ForeColor = System.Drawing.Color.Red;
            this.ExitButton.Location = new System.Drawing.Point(1003, 572);
            this.ExitButton.Name = "ExitButton";
            this.ExitButton.Size = new System.Drawing.Size(121, 43);
            this.ExitButton.TabIndex = 13;
            this.ExitButton.Text = "Exit";
            this.ExitButton.UseVisualStyleBackColor = true;
            this.ExitButton.Click += new System.EventHandler(this.ExitButton_Click);
            // 
            // Timer
            // 
            this.Timer.Enabled = true;
            this.Timer.Interval = 1000;
            this.Timer.Tick += new System.EventHandler(this.Timer_Tick);
            // 
            // AccountScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Silver;
            this.ClientSize = new System.Drawing.Size(1184, 681);
            this.Controls.Add(this.ExitButton);
            this.Controls.Add(this.ApproveEftButton);
            this.Controls.Add(this.AlertMessageLabel);
            this.Controls.Add(this.InformationIV);
            this.Controls.Add(this.MoneyBox);
            this.Controls.Add(this.ChoosenIBANComboBox);
            this.Controls.Add(this.InformationIII);
            this.Controls.Add(this.IBANComboBox);
            this.Controls.Add(this.InformationII);
            this.Controls.Add(this.PersonComboBox);
            this.Controls.Add(this.InformationI);
            this.Controls.Add(this.CurrencyPanel);
            this.Controls.Add(this.NameLabel);
            this.Controls.Add(this.WelcomeLabel);
            this.MaximumSize = new System.Drawing.Size(1200, 720);
            this.MinimumSize = new System.Drawing.Size(1200, 720);
            this.Name = "AccountScreen";
            this.Text = "AccountScreen";
            this.Load += new System.EventHandler(this.AccountScreen_Load);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.AccountScreen_MouseMove);
            this.CurrencyPanel.ResumeLayout(false);
            this.CurrencyPanel.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label WelcomeLabel;
        private System.Windows.Forms.Label NameLabel;
        private System.Windows.Forms.Panel CurrencyPanel;
        private System.Windows.Forms.Label CurrencyInfo;
        private System.Windows.Forms.Label InformationI;
        private System.Windows.Forms.ComboBox PersonComboBox;
        private System.Windows.Forms.Label InformationII;
        private System.Windows.Forms.ComboBox IBANComboBox;
        private System.Windows.Forms.Label InformationIII;
        private System.Windows.Forms.ComboBox ChoosenIBANComboBox;
        private System.Windows.Forms.MaskedTextBox MoneyBox;
        private System.Windows.Forms.Label InformationIV;
        private System.Windows.Forms.Label AlertMessageLabel;
        private System.Windows.Forms.Button ApproveEftButton;
        private System.Windows.Forms.Button ExitButton;
        private System.Windows.Forms.Timer Timer;
    }
}