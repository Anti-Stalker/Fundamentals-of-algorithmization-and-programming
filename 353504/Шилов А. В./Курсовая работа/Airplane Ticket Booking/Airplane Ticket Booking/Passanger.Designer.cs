namespace Airplane_Ticket_Booking
{
    partial class Passanger
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Passanger));
            this.label6 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.Button2 = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.PassId = new System.Windows.Forms.TextBox();
            this.passangerTblBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.airlineDbDataSet = new Airplane_Ticket_Booking.AirlineDbDataSet();
            this.Label2 = new System.Windows.Forms.Label();
            this.PassName = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.PassportTb = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.PassAd = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.PhoneTb = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.GenderCb = new System.Windows.Forms.ComboBox();
            this.NationalityCb = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.ViewPassngrBtn = new Bunifu.Framework.UI.BunifuThinButton2();
            this.ResetBtn = new Bunifu.Framework.UI.BunifuThinButton2();
            this.RecordBtn = new Bunifu.Framework.UI.BunifuThinButton2();
            this.pictureBox3 = new System.Windows.Forms.PictureBox();
            this.passangerTblTableAdapter = new Airplane_Ticket_Booking.AirlineDbDataSetTableAdapters.PassangerTblTableAdapter();
            this.Backbtn = new Bunifu.Framework.UI.BunifuThinButton2();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.passangerTblBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.airlineDbDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
            this.SuspendLayout();
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Century", 22.2F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Italic | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.Navy;
            this.label6.Location = new System.Drawing.Point(343, 156);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(414, 44);
            this.label6.TabIndex = 34;
            this.label6.Text = "Record New Passanger";
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.Navy;
            this.panel2.Controls.Add(this.label1);
            this.panel2.Controls.Add(this.Button2);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(1191, 122);
            this.panel2.TabIndex = 33;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Century", 36F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Italic | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.AliceBlue;
            this.label1.Location = new System.Drawing.Point(323, 17);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(481, 71);
            this.label1.TabIndex = 30;
            this.label1.Text = "SkyJet Airplane";
            // 
            // Button2
            // 
            this.Button2.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("Button2.BackgroundImage")));
            this.Button2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.Button2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.Button2.FlatAppearance.BorderColor = System.Drawing.SystemColors.ButtonFace;
            this.Button2.FlatAppearance.BorderSize = 0;
            this.Button2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Button2.Location = new System.Drawing.Point(1132, 7);
            this.Button2.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Button2.Name = "Button2";
            this.Button2.Size = new System.Drawing.Size(49, 49);
            this.Button2.TabIndex = 21;
            this.Button2.UseVisualStyleBackColor = true;
            this.Button2.Click += new System.EventHandler(this.Button2_Click);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.Navy;
            this.panel1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel1.Location = new System.Drawing.Point(0, 880);
            this.panel1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1191, 20);
            this.panel1.TabIndex = 32;
            // 
            // PassId
            // 
            this.PassId.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.passangerTblBindingSource, "PassId", true));
            this.PassId.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PassId.Location = new System.Drawing.Point(335, 244);
            this.PassId.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.PassId.Name = "PassId";
            this.PassId.Size = new System.Drawing.Size(283, 36);
            this.PassId.TabIndex = 48;
            this.PassId.TextChanged += new System.EventHandler(this.PassId_TextChanged);
            // 
            // passangerTblBindingSource
            // 
            this.passangerTblBindingSource.DataMember = "PassangerTbl";
            this.passangerTblBindingSource.DataSource = this.airlineDbDataSet;
            // 
            // airlineDbDataSet
            // 
            this.airlineDbDataSet.DataSetName = "AirlineDbDataSet";
            this.airlineDbDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // Label2
            // 
            this.Label2.AutoSize = true;
            this.Label2.BackColor = System.Drawing.SystemColors.Control;
            this.Label2.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Label2.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.Label2.Location = new System.Drawing.Point(36, 241);
            this.Label2.Name = "Label2";
            this.Label2.Size = new System.Drawing.Size(187, 34);
            this.Label2.TabIndex = 47;
            this.Label2.Text = "Passanger Id";
            // 
            // PassName
            // 
            this.PassName.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.passangerTblBindingSource, "PassName", true));
            this.PassName.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PassName.Location = new System.Drawing.Point(335, 316);
            this.PassName.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.PassName.Name = "PassName";
            this.PassName.Size = new System.Drawing.Size(283, 36);
            this.PassName.TabIndex = 50;
            this.PassName.TextChanged += new System.EventHandler(this.PassName_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.SystemColors.Control;
            this.label3.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label3.Location = new System.Drawing.Point(36, 315);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(246, 34);
            this.label3.TabIndex = 49;
            this.label3.Text = "Passanger Name";
            // 
            // PassportTb
            // 
            this.PassportTb.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.passangerTblBindingSource, "Passport", true));
            this.PassportTb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PassportTb.Location = new System.Drawing.Point(335, 388);
            this.PassportTb.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.PassportTb.Name = "PassportTb";
            this.PassportTb.Size = new System.Drawing.Size(283, 36);
            this.PassportTb.TabIndex = 52;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.SystemColors.Control;
            this.label4.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label4.Location = new System.Drawing.Point(36, 385);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(245, 34);
            this.label4.TabIndex = 51;
            this.label4.Text = "Passport Number";
            // 
            // PassAd
            // 
            this.PassAd.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.passangerTblBindingSource, "PassAd", true));
            this.PassAd.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PassAd.Location = new System.Drawing.Point(335, 460);
            this.PassAd.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.PassAd.Name = "PassAd";
            this.PassAd.Size = new System.Drawing.Size(283, 36);
            this.PassAd.TabIndex = 54;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.SystemColors.Control;
            this.label5.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label5.Location = new System.Drawing.Point(36, 459);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(269, 34);
            this.label5.TabIndex = 53;
            this.label5.Text = "Passanger Address";
            // 
            // PhoneTb
            // 
            this.PhoneTb.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.passangerTblBindingSource, "PassPhone", true));
            this.PhoneTb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PhoneTb.Location = new System.Drawing.Point(335, 672);
            this.PhoneTb.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.PhoneTb.Name = "PhoneTb";
            this.PhoneTb.Size = new System.Drawing.Size(283, 36);
            this.PhoneTb.TabIndex = 56;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.SystemColors.Control;
            this.label7.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label7.Location = new System.Drawing.Point(36, 671);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(156, 34);
            this.label7.TabIndex = 55;
            this.label7.Text = "Phone No.";
            // 
            // GenderCb
            // 
            this.GenderCb.DataBindings.Add(new System.Windows.Forms.Binding("SelectedItem", this.passangerTblBindingSource, "PassGend", true));
            this.GenderCb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.GenderCb.FormattingEnabled = true;
            this.GenderCb.Items.AddRange(new object[] {
            "MALE",
            "FEMALE"});
            this.GenderCb.Location = new System.Drawing.Point(335, 604);
            this.GenderCb.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.GenderCb.Name = "GenderCb";
            this.GenderCb.Size = new System.Drawing.Size(283, 35);
            this.GenderCb.TabIndex = 60;
            // 
            // NationalityCb
            // 
            this.NationalityCb.DataBindings.Add(new System.Windows.Forms.Binding("SelectedItem", this.passangerTblBindingSource, "PassNat", true));
            this.NationalityCb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.NationalityCb.FormattingEnabled = true;
            this.NationalityCb.Items.AddRange(new object[] {
            "INDIAN",
            "PAKISTANI",
            "CHINESE",
            "AMERICAN",
            "NIGERIAN",
            "SPANISH",
            "TURKISH",
            "EROPIAN"});
            this.NationalityCb.Location = new System.Drawing.Point(335, 529);
            this.NationalityCb.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.NationalityCb.Name = "NationalityCb";
            this.NationalityCb.Size = new System.Drawing.Size(283, 35);
            this.NationalityCb.TabIndex = 59;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BackColor = System.Drawing.SystemColors.Control;
            this.label8.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label8.Location = new System.Drawing.Point(36, 528);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(164, 34);
            this.label8.TabIndex = 58;
            this.label8.Text = "Nationality";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.BackColor = System.Drawing.SystemColors.Control;
            this.label9.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label9.Location = new System.Drawing.Point(36, 602);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(119, 34);
            this.label9.TabIndex = 57;
            this.label9.Text = "Gender";
            // 
            // ViewPassngrBtn
            // 
            this.ViewPassngrBtn.ActiveBorderThickness = 1;
            this.ViewPassngrBtn.ActiveCornerRadius = 20;
            this.ViewPassngrBtn.ActiveFillColor = System.Drawing.Color.SeaGreen;
            this.ViewPassngrBtn.ActiveForecolor = System.Drawing.Color.White;
            this.ViewPassngrBtn.ActiveLineColor = System.Drawing.Color.SeaGreen;
            this.ViewPassngrBtn.BackColor = System.Drawing.SystemColors.Control;
            this.ViewPassngrBtn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("ViewPassngrBtn.BackgroundImage")));
            this.ViewPassngrBtn.ButtonText = "View Passanger";
            this.ViewPassngrBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ViewPassngrBtn.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ViewPassngrBtn.ForeColor = System.Drawing.Color.SeaGreen;
            this.ViewPassngrBtn.IdleBorderThickness = 1;
            this.ViewPassngrBtn.IdleCornerRadius = 20;
            this.ViewPassngrBtn.IdleFillColor = System.Drawing.Color.Gold;
            this.ViewPassngrBtn.IdleForecolor = System.Drawing.Color.Black;
            this.ViewPassngrBtn.IdleLineColor = System.Drawing.Color.Gold;
            this.ViewPassngrBtn.Location = new System.Drawing.Point(392, 783);
            this.ViewPassngrBtn.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.ViewPassngrBtn.Name = "ViewPassngrBtn";
            this.ViewPassngrBtn.Size = new System.Drawing.Size(323, 59);
            this.ViewPassngrBtn.TabIndex = 63;
            this.ViewPassngrBtn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.ViewPassngrBtn.Click += new System.EventHandler(this.ViewPassngrBtn_Click);
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
            this.ResetBtn.Location = new System.Drawing.Point(468, 719);
            this.ResetBtn.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.ResetBtn.Name = "ResetBtn";
            this.ResetBtn.Size = new System.Drawing.Size(197, 59);
            this.ResetBtn.TabIndex = 62;
            this.ResetBtn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.ResetBtn.Click += new System.EventHandler(this.ResetBtn_Click);
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
            this.RecordBtn.Location = new System.Drawing.Point(257, 719);
            this.RecordBtn.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.RecordBtn.Name = "RecordBtn";
            this.RecordBtn.Size = new System.Drawing.Size(197, 59);
            this.RecordBtn.TabIndex = 61;
            this.RecordBtn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.RecordBtn.Click += new System.EventHandler(this.RecordBtn_Click);
            // 
            // pictureBox3
            // 
            this.pictureBox3.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox3.Image")));
            this.pictureBox3.Location = new System.Drawing.Point(637, 279);
            this.pictureBox3.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.pictureBox3.Name = "pictureBox3";
            this.pictureBox3.Size = new System.Drawing.Size(553, 384);
            this.pictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox3.TabIndex = 64;
            this.pictureBox3.TabStop = false;
            // 
            // passangerTblTableAdapter
            // 
            this.passangerTblTableAdapter.ClearBeforeFill = true;
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
            this.Backbtn.Location = new System.Drawing.Point(679, 719);
            this.Backbtn.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.Backbtn.Name = "Backbtn";
            this.Backbtn.Size = new System.Drawing.Size(197, 59);
            this.Backbtn.TabIndex = 65;
            this.Backbtn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.Backbtn.Click += new System.EventHandler(this.Backbtn_Click);
            // 
            // Passanger
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1191, 900);
            this.Controls.Add(this.Backbtn);
            this.Controls.Add(this.pictureBox3);
            this.Controls.Add(this.ViewPassngrBtn);
            this.Controls.Add(this.ResetBtn);
            this.Controls.Add(this.RecordBtn);
            this.Controls.Add(this.GenderCb);
            this.Controls.Add(this.NationalityCb);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.PhoneTb);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.PassAd);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.PassportTb);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.PassName);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.PassId);
            this.Controls.Add(this.Label2);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "Passanger";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Passanger";
            this.Load += new System.EventHandler(this.Passanger_Load);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.passangerTblBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.airlineDbDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label label1;
        internal System.Windows.Forms.Button Button2;
        private System.Windows.Forms.Panel panel1;
        internal System.Windows.Forms.TextBox PassId;
        internal System.Windows.Forms.Label Label2;
        internal System.Windows.Forms.TextBox PassName;
        internal System.Windows.Forms.Label label3;
        internal System.Windows.Forms.TextBox PassportTb;
        internal System.Windows.Forms.Label label4;
        internal System.Windows.Forms.TextBox PassAd;
        internal System.Windows.Forms.Label label5;
        internal System.Windows.Forms.TextBox PhoneTb;
        internal System.Windows.Forms.Label label7;
        private System.Windows.Forms.ComboBox GenderCb;
        private System.Windows.Forms.ComboBox NationalityCb;
        internal System.Windows.Forms.Label label8;
        internal System.Windows.Forms.Label label9;
        internal Bunifu.Framework.UI.BunifuThinButton2 ViewPassngrBtn;
        internal Bunifu.Framework.UI.BunifuThinButton2 ResetBtn;
        internal Bunifu.Framework.UI.BunifuThinButton2 RecordBtn;
        private System.Windows.Forms.PictureBox pictureBox3;
        private AirlineDbDataSet airlineDbDataSet;
        private System.Windows.Forms.BindingSource passangerTblBindingSource;
        private AirlineDbDataSetTableAdapters.PassangerTblTableAdapter passangerTblTableAdapter;
        internal Bunifu.Framework.UI.BunifuThinButton2 Backbtn;
    }
}