namespace Airplane_Ticket_Booking
{
    partial class Flight
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Flight));
            this.Button2 = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.FCodeTb = new System.Windows.Forms.TextBox();
            this.Label2 = new System.Windows.Forms.Label();
            this.NumSeatTb = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.SourceCb = new System.Windows.Forms.ComboBox();
            this.DestinationCb = new System.Windows.Forms.ComboBox();
            this.RecordBtn = new Bunifu.Framework.UI.BunifuThinButton2();
            this.ResetBtn = new Bunifu.Framework.UI.BunifuThinButton2();
            this.pictureBox3 = new System.Windows.Forms.PictureBox();
            this.label6 = new System.Windows.Forms.Label();
            this.ViewFlightBtn = new Bunifu.Framework.UI.BunifuThinButton2();
            this.label7 = new System.Windows.Forms.Label();
            this.DateDtp = new System.Windows.Forms.DateTimePicker();
            this.Backbtn = new Bunifu.Framework.UI.BunifuThinButton2();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
            this.SuspendLayout();
            // 
            // Button2
            // 
            this.Button2.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("Button2.BackgroundImage")));
            this.Button2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.Button2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.Button2.FlatAppearance.BorderColor = System.Drawing.SystemColors.ButtonFace;
            this.Button2.FlatAppearance.BorderSize = 0;
            this.Button2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Button2.Location = new System.Drawing.Point(1026, 3);
            this.Button2.Name = "Button2";
            this.Button2.Size = new System.Drawing.Size(50, 49);
            this.Button2.TabIndex = 21;
            this.Button2.UseVisualStyleBackColor = true;
            this.Button2.Click += new System.EventHandler(this.Button2_Click);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.Navy;
            this.panel1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel1.Location = new System.Drawing.Point(0, 864);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1080, 19);
            this.panel1.TabIndex = 29;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Century", 36F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Italic | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.AliceBlue;
            this.label1.Location = new System.Drawing.Point(323, 18);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(481, 71);
            this.label1.TabIndex = 30;
            this.label1.Text = "SkyJet Airplane";
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.Navy;
            this.panel2.Controls.Add(this.label1);
            this.panel2.Controls.Add(this.Button2);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(1080, 122);
            this.panel2.TabIndex = 30;
            // 
            // FCodeTb
            // 
            this.FCodeTb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FCodeTb.Location = new System.Drawing.Point(243, 293);
            this.FCodeTb.Name = "FCodeTb";
            this.FCodeTb.Size = new System.Drawing.Size(283, 36);
            this.FCodeTb.TabIndex = 32;
            this.FCodeTb.TextChanged += new System.EventHandler(this.FCodeTb_TextChanged);
            // 
            // Label2
            // 
            this.Label2.AutoSize = true;
            this.Label2.BackColor = System.Drawing.SystemColors.Control;
            this.Label2.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Label2.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.Label2.Location = new System.Drawing.Point(19, 291);
            this.Label2.Name = "Label2";
            this.Label2.Size = new System.Drawing.Size(174, 34);
            this.Label2.TabIndex = 31;
            this.Label2.Text = "Flight Code";
            // 
            // NumSeatTb
            // 
            this.NumSeatTb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.NumSeatTb.Location = new System.Drawing.Point(243, 585);
            this.NumSeatTb.Name = "NumSeatTb";
            this.NumSeatTb.Size = new System.Drawing.Size(283, 36);
            this.NumSeatTb.TabIndex = 34;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.SystemColors.Control;
            this.label3.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label3.Location = new System.Drawing.Point(19, 583);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(179, 34);
            this.label3.TabIndex = 33;
            this.label3.Text = "num of Seat";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.SystemColors.Control;
            this.label4.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label4.Location = new System.Drawing.Point(19, 444);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(170, 34);
            this.label4.TabIndex = 36;
            this.label4.Text = "Destination";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.SystemColors.Control;
            this.label5.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label5.Location = new System.Drawing.Point(19, 366);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(108, 34);
            this.label5.TabIndex = 35;
            this.label5.Text = "Source";
            // 
            // SourceCb
            // 
            this.SourceCb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SourceCb.FormattingEnabled = true;
            this.SourceCb.Items.AddRange(new object[] {
            "Ahemdabad",
            "Rajkot",
            "Surat",
            "Vdodara",
            "Banglore",
            "Mumbai",
            "Delhi",
            "Chennai",
            "Kolkata",
            "uttrakhand",
            "U.S"});
            this.SourceCb.Location = new System.Drawing.Point(243, 368);
            this.SourceCb.Name = "SourceCb";
            this.SourceCb.Size = new System.Drawing.Size(283, 35);
            this.SourceCb.TabIndex = 37;
            // 
            // DestinationCb
            // 
            this.DestinationCb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.DestinationCb.FormattingEnabled = true;
            this.DestinationCb.Items.AddRange(new object[] {
            "Ahemdabad",
            "Rajkot",
            "Surat",
            "Vdodara",
            "Banglore",
            "Mumbai",
            "Delhi",
            "Chennai",
            "Kolkata",
            "uttrakhand",
            "U.S"});
            this.DestinationCb.Location = new System.Drawing.Point(243, 446);
            this.DestinationCb.Name = "DestinationCb";
            this.DestinationCb.Size = new System.Drawing.Size(283, 35);
            this.DestinationCb.TabIndex = 38;
            // 
            // RecordBtn
            // 
            this.RecordBtn.ActiveBorderThickness = 1;
            this.RecordBtn.ActiveCornerRadius = 20;
            this.RecordBtn.ActiveFillColor = System.Drawing.Color.SeaGreen;
            this.RecordBtn.ActiveForecolor = System.Drawing.Color.White;
            this.RecordBtn.ActiveLineColor = System.Drawing.Color.SeaGreen;
            this.RecordBtn.BackColor = System.Drawing.SystemColors.Control;
            this.RecordBtn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("RecordBtn.BackgroundImage")));
            this.RecordBtn.ButtonText = "Record";
            this.RecordBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.RecordBtn.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RecordBtn.ForeColor = System.Drawing.Color.SeaGreen;
            this.RecordBtn.IdleBorderThickness = 1;
            this.RecordBtn.IdleCornerRadius = 20;
            this.RecordBtn.IdleFillColor = System.Drawing.Color.Gold;
            this.RecordBtn.IdleForecolor = System.Drawing.Color.Black;
            this.RecordBtn.IdleLineColor = System.Drawing.Color.Gold;
            this.RecordBtn.Location = new System.Drawing.Point(141, 681);
            this.RecordBtn.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.RecordBtn.Name = "RecordBtn";
            this.RecordBtn.Size = new System.Drawing.Size(197, 59);
            this.RecordBtn.TabIndex = 39;
            this.RecordBtn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.RecordBtn.Click += new System.EventHandler(this.RecordBtn_Click);
            // 
            // ResetBtn
            // 
            this.ResetBtn.ActiveBorderThickness = 1;
            this.ResetBtn.ActiveCornerRadius = 20;
            this.ResetBtn.ActiveFillColor = System.Drawing.Color.SeaGreen;
            this.ResetBtn.ActiveForecolor = System.Drawing.Color.White;
            this.ResetBtn.ActiveLineColor = System.Drawing.Color.SeaGreen;
            this.ResetBtn.BackColor = System.Drawing.SystemColors.Control;
            this.ResetBtn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("ResetBtn.BackgroundImage")));
            this.ResetBtn.ButtonText = "Reset";
            this.ResetBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ResetBtn.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ResetBtn.ForeColor = System.Drawing.Color.SeaGreen;
            this.ResetBtn.IdleBorderThickness = 1;
            this.ResetBtn.IdleCornerRadius = 20;
            this.ResetBtn.IdleFillColor = System.Drawing.Color.Gold;
            this.ResetBtn.IdleForecolor = System.Drawing.Color.Black;
            this.ResetBtn.IdleLineColor = System.Drawing.Color.Gold;
            this.ResetBtn.Location = new System.Drawing.Point(352, 681);
            this.ResetBtn.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.ResetBtn.Name = "ResetBtn";
            this.ResetBtn.Size = new System.Drawing.Size(197, 59);
            this.ResetBtn.TabIndex = 40;
            this.ResetBtn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.ResetBtn.Click += new System.EventHandler(this.ResetBtn_Click);
            // 
            // pictureBox3
            // 
            this.pictureBox3.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox3.Image")));
            this.pictureBox3.Location = new System.Drawing.Point(575, 270);
            this.pictureBox3.Name = "pictureBox3";
            this.pictureBox3.Size = new System.Drawing.Size(493, 402);
            this.pictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox3.TabIndex = 41;
            this.pictureBox3.TabStop = false;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Century", 22.2F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Italic | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.Navy;
            this.label6.Location = new System.Drawing.Point(397, 157);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(341, 44);
            this.label6.TabIndex = 31;
            this.label6.Text = "Record New Flight";
            // 
            // ViewFlightBtn
            // 
            this.ViewFlightBtn.ActiveBorderThickness = 1;
            this.ViewFlightBtn.ActiveCornerRadius = 20;
            this.ViewFlightBtn.ActiveFillColor = System.Drawing.Color.SeaGreen;
            this.ViewFlightBtn.ActiveForecolor = System.Drawing.Color.White;
            this.ViewFlightBtn.ActiveLineColor = System.Drawing.Color.SeaGreen;
            this.ViewFlightBtn.BackColor = System.Drawing.SystemColors.Control;
            this.ViewFlightBtn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("ViewFlightBtn.BackgroundImage")));
            this.ViewFlightBtn.ButtonText = "View Flights";
            this.ViewFlightBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ViewFlightBtn.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ViewFlightBtn.ForeColor = System.Drawing.Color.SeaGreen;
            this.ViewFlightBtn.IdleBorderThickness = 1;
            this.ViewFlightBtn.IdleCornerRadius = 20;
            this.ViewFlightBtn.IdleFillColor = System.Drawing.Color.Gold;
            this.ViewFlightBtn.IdleForecolor = System.Drawing.Color.Black;
            this.ViewFlightBtn.IdleLineColor = System.Drawing.Color.Gold;
            this.ViewFlightBtn.Location = new System.Drawing.Point(275, 754);
            this.ViewFlightBtn.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.ViewFlightBtn.Name = "ViewFlightBtn";
            this.ViewFlightBtn.Size = new System.Drawing.Size(340, 59);
            this.ViewFlightBtn.TabIndex = 42;
            this.ViewFlightBtn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.ViewFlightBtn.Click += new System.EventHandler(this.ViewFlightBtn_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.SystemColors.Control;
            this.label7.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label7.Location = new System.Drawing.Point(19, 516);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(199, 34);
            this.label7.TabIndex = 43;
            this.label7.Text = "Tack OF Date";
            // 
            // DateDtp
            // 
            this.DateDtp.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.DateDtp.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.DateDtp.Location = new System.Drawing.Point(243, 516);
            this.DateDtp.Name = "DateDtp";
            this.DateDtp.Size = new System.Drawing.Size(283, 36);
            this.DateDtp.TabIndex = 44;
            // 
            // Backbtn
            // 
            this.Backbtn.ActiveBorderThickness = 1;
            this.Backbtn.ActiveCornerRadius = 20;
            this.Backbtn.ActiveFillColor = System.Drawing.Color.SeaGreen;
            this.Backbtn.ActiveForecolor = System.Drawing.Color.White;
            this.Backbtn.ActiveLineColor = System.Drawing.Color.SeaGreen;
            this.Backbtn.BackColor = System.Drawing.SystemColors.Control;
            this.Backbtn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("Backbtn.BackgroundImage")));
            this.Backbtn.ButtonText = "Back";
            this.Backbtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.Backbtn.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Backbtn.ForeColor = System.Drawing.Color.SeaGreen;
            this.Backbtn.IdleBorderThickness = 1;
            this.Backbtn.IdleCornerRadius = 20;
            this.Backbtn.IdleFillColor = System.Drawing.Color.Gold;
            this.Backbtn.IdleForecolor = System.Drawing.Color.Black;
            this.Backbtn.IdleLineColor = System.Drawing.Color.Gold;
            this.Backbtn.Location = new System.Drawing.Point(563, 681);
            this.Backbtn.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.Backbtn.Name = "Backbtn";
            this.Backbtn.Size = new System.Drawing.Size(197, 59);
            this.Backbtn.TabIndex = 66;
            this.Backbtn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.Backbtn.Click += new System.EventHandler(this.Backbtn_Click);
            // 
            // Flight
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1080, 883);
            this.Controls.Add(this.Backbtn);
            this.Controls.Add(this.DateDtp);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.ViewFlightBtn);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.pictureBox3);
            this.Controls.Add(this.ResetBtn);
            this.Controls.Add(this.RecordBtn);
            this.Controls.Add(this.DestinationCb);
            this.Controls.Add(this.SourceCb);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.NumSeatTb);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.FCodeTb);
            this.Controls.Add(this.Label2);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Flight";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Flight";
            this.Load += new System.EventHandler(this.Flight_Load);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        internal System.Windows.Forms.Button Button2;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel2;
        internal System.Windows.Forms.TextBox FCodeTb;
        internal System.Windows.Forms.Label Label2;
        internal System.Windows.Forms.TextBox NumSeatTb;
        internal System.Windows.Forms.Label label3;
        internal System.Windows.Forms.Label label4;
        internal System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox SourceCb;
        private System.Windows.Forms.ComboBox DestinationCb;
        internal Bunifu.Framework.UI.BunifuThinButton2 RecordBtn;
        internal Bunifu.Framework.UI.BunifuThinButton2 ResetBtn;
        private System.Windows.Forms.PictureBox pictureBox3;
        private System.Windows.Forms.Label label6;
        internal Bunifu.Framework.UI.BunifuThinButton2 ViewFlightBtn;
        internal System.Windows.Forms.Label label7;
        private System.Windows.Forms.DateTimePicker DateDtp;
        internal Bunifu.Framework.UI.BunifuThinButton2 Backbtn;
    }
}