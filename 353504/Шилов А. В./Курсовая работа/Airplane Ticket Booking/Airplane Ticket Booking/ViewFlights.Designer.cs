namespace Airplane_Ticket_Booking
{
    partial class ViewFlights
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ViewFlights));
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle4 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle5 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle6 = new System.Windows.Forms.DataGridViewCellStyle();
            this.panel2 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.Button2 = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label6 = new System.Windows.Forms.Label();
            this.FDate = new System.Windows.Forms.DateTimePicker();
            this.label7 = new System.Windows.Forms.Label();
            this.DestiCb = new System.Windows.Forms.ComboBox();
            this.SrcCb = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.SeatTb = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.FcodeTb = new System.Windows.Forms.TextBox();
            this.Label2 = new System.Windows.Forms.Label();
            this.FlightDGV = new System.Windows.Forms.DataGridView();
            this.ResetBtn = new Bunifu.Framework.UI.BunifuThinButton2();
            this.DeleteBtn = new Bunifu.Framework.UI.BunifuThinButton2();
            this.UpdateBtn = new Bunifu.Framework.UI.BunifuThinButton2();
            this.BackBtn = new Bunifu.Framework.UI.BunifuThinButton2();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.FlightDGV)).BeginInit();
            this.SuspendLayout();
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
            this.panel2.TabIndex = 31;
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
            this.panel1.Location = new System.Drawing.Point(0, 838);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1080, 19);
            this.panel1.TabIndex = 32;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Century", 22.2F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Italic | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.Navy;
            this.label6.Location = new System.Drawing.Point(349, 158);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(432, 44);
            this.label6.TabIndex = 33;
            this.label6.Text = "View Scheduling Flight";
            // 
            // FDate
            // 
            this.FDate.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FDate.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.FDate.Location = new System.Drawing.Point(785, 325);
            this.FDate.Name = "FDate";
            this.FDate.Size = new System.Drawing.Size(283, 36);
            this.FDate.TabIndex = 54;
            this.FDate.ValueChanged += new System.EventHandler(this.FDate_ValueChanged);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.SystemColors.Control;
            this.label7.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label7.Location = new System.Drawing.Point(561, 325);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(199, 34);
            this.label7.TabIndex = 53;
            this.label7.Text = "Tack OF Date";
            this.label7.Click += new System.EventHandler(this.label7_Click);
            // 
            // DestiCb
            // 
            this.DestiCb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.DestiCb.FormattingEnabled = true;
            this.DestiCb.Items.AddRange(new object[] {
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
            this.DestiCb.Location = new System.Drawing.Point(236, 329);
            this.DestiCb.Name = "DestiCb";
            this.DestiCb.Size = new System.Drawing.Size(283, 35);
            this.DestiCb.TabIndex = 52;
            // 
            // SrcCb
            // 
            this.SrcCb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SrcCb.FormattingEnabled = true;
            this.SrcCb.Items.AddRange(new object[] {
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
            this.SrcCb.Location = new System.Drawing.Point(785, 251);
            this.SrcCb.Name = "SrcCb";
            this.SrcCb.Size = new System.Drawing.Size(283, 35);
            this.SrcCb.TabIndex = 51;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.SystemColors.Control;
            this.label4.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label4.Location = new System.Drawing.Point(12, 327);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(170, 34);
            this.label4.TabIndex = 50;
            this.label4.Text = "Destination";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.SystemColors.Control;
            this.label5.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label5.Location = new System.Drawing.Point(561, 249);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(108, 34);
            this.label5.TabIndex = 49;
            this.label5.Text = "Source";
            // 
            // SeatTb
            // 
            this.SeatTb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SeatTb.Location = new System.Drawing.Point(541, 397);
            this.SeatTb.Name = "SeatTb";
            this.SeatTb.Size = new System.Drawing.Size(283, 36);
            this.SeatTb.TabIndex = 48;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.SystemColors.Control;
            this.label3.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label3.Location = new System.Drawing.Point(317, 395);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(179, 34);
            this.label3.TabIndex = 47;
            this.label3.Text = "num of Seat";
            // 
            // FcodeTb
            // 
            this.FcodeTb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FcodeTb.Location = new System.Drawing.Point(236, 252);
            this.FcodeTb.Name = "FcodeTb";
            this.FcodeTb.Size = new System.Drawing.Size(283, 36);
            this.FcodeTb.TabIndex = 46;
            // 
            // Label2
            // 
            this.Label2.AutoSize = true;
            this.Label2.BackColor = System.Drawing.SystemColors.Control;
            this.Label2.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Label2.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.Label2.Location = new System.Drawing.Point(12, 249);
            this.Label2.Name = "Label2";
            this.Label2.Size = new System.Drawing.Size(174, 34);
            this.Label2.TabIndex = 45;
            this.Label2.Text = "Flight Code";
            // 
            // FlightDGV
            // 
            this.FlightDGV.AllowUserToAddRows = false;
            this.FlightDGV.AllowUserToOrderColumns = true;
            this.FlightDGV.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.FlightDGV.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.DisplayedCells;
            this.FlightDGV.BackgroundColor = System.Drawing.Color.White;
            this.FlightDGV.CellBorderStyle = System.Windows.Forms.DataGridViewCellBorderStyle.None;
            this.FlightDGV.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.None;
            dataGridViewCellStyle4.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle4.BackColor = System.Drawing.Color.Navy;
            dataGridViewCellStyle4.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle4.ForeColor = System.Drawing.Color.White;
            dataGridViewCellStyle4.SelectionBackColor = System.Drawing.Color.Navy;
            dataGridViewCellStyle4.SelectionForeColor = System.Drawing.Color.Lavender;
            dataGridViewCellStyle4.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.FlightDGV.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
            this.FlightDGV.ColumnHeadersHeight = 28;
            this.FlightDGV.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.DisableResizing;
            this.FlightDGV.Cursor = System.Windows.Forms.Cursors.Default;
            dataGridViewCellStyle5.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle5.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle5.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle5.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle5.SelectionBackColor = System.Drawing.Color.Gold;
            dataGridViewCellStyle5.SelectionForeColor = System.Drawing.Color.DarkBlue;
            dataGridViewCellStyle5.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.FlightDGV.DefaultCellStyle = dataGridViewCellStyle5;
            this.FlightDGV.EnableHeadersVisualStyles = false;
            this.FlightDGV.GridColor = System.Drawing.Color.White;
            this.FlightDGV.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.FlightDGV.Location = new System.Drawing.Point(12, 530);
            this.FlightDGV.Name = "FlightDGV";
            this.FlightDGV.ReadOnly = true;
            dataGridViewCellStyle6.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle6.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle6.Font = new System.Drawing.Font("Century Gothic", 14.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle6.ForeColor = System.Drawing.SystemColors.Info;
            dataGridViewCellStyle6.SelectionBackColor = System.Drawing.Color.Gold;
            dataGridViewCellStyle6.SelectionForeColor = System.Drawing.Color.DarkBlue;
            dataGridViewCellStyle6.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.FlightDGV.RowHeadersDefaultCellStyle = dataGridViewCellStyle6;
            this.FlightDGV.RowTemplate.Height = 24;
            this.FlightDGV.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.FlightDGV.Size = new System.Drawing.Size(1056, 305);
            this.FlightDGV.TabIndex = 85;
            this.FlightDGV.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.FlightDGV_CellContentClick);
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
            this.ResetBtn.Location = new System.Drawing.Point(557, 461);
            this.ResetBtn.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.ResetBtn.Name = "ResetBtn";
            this.ResetBtn.Size = new System.Drawing.Size(213, 59);
            this.ResetBtn.TabIndex = 89;
            this.ResetBtn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.ResetBtn.Click += new System.EventHandler(this.ResetBtn_Click);
            // 
            // DeleteBtn
            // 
            this.DeleteBtn.ActiveBorderThickness = 1;
            this.DeleteBtn.ActiveCornerRadius = 20;
            this.DeleteBtn.ActiveFillColor = System.Drawing.Color.SeaGreen;
            this.DeleteBtn.ActiveForecolor = System.Drawing.Color.White;
            this.DeleteBtn.ActiveLineColor = System.Drawing.Color.SeaGreen;
            this.DeleteBtn.BackColor = System.Drawing.SystemColors.Control;
            this.DeleteBtn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("DeleteBtn.BackgroundImage")));
            this.DeleteBtn.ButtonText = "Delete";
            this.DeleteBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.DeleteBtn.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.DeleteBtn.ForeColor = System.Drawing.Color.SeaGreen;
            this.DeleteBtn.IdleBorderThickness = 1;
            this.DeleteBtn.IdleCornerRadius = 20;
            this.DeleteBtn.IdleFillColor = System.Drawing.Color.Gold;
            this.DeleteBtn.IdleForecolor = System.Drawing.Color.Black;
            this.DeleteBtn.IdleLineColor = System.Drawing.Color.Gold;
            this.DeleteBtn.Location = new System.Drawing.Point(322, 461);
            this.DeleteBtn.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.DeleteBtn.Name = "DeleteBtn";
            this.DeleteBtn.Size = new System.Drawing.Size(197, 59);
            this.DeleteBtn.TabIndex = 87;
            this.DeleteBtn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.DeleteBtn.Click += new System.EventHandler(this.DeleteBtn_Click);
            // 
            // UpdateBtn
            // 
            this.UpdateBtn.ActiveBorderThickness = 1;
            this.UpdateBtn.ActiveCornerRadius = 20;
            this.UpdateBtn.ActiveFillColor = System.Drawing.Color.SeaGreen;
            this.UpdateBtn.ActiveForecolor = System.Drawing.Color.White;
            this.UpdateBtn.ActiveLineColor = System.Drawing.Color.SeaGreen;
            this.UpdateBtn.BackColor = System.Drawing.SystemColors.Control;
            this.UpdateBtn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("UpdateBtn.BackgroundImage")));
            this.UpdateBtn.ButtonText = "Update";
            this.UpdateBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.UpdateBtn.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.UpdateBtn.ForeColor = System.Drawing.Color.SeaGreen;
            this.UpdateBtn.IdleBorderThickness = 1;
            this.UpdateBtn.IdleCornerRadius = 20;
            this.UpdateBtn.IdleFillColor = System.Drawing.Color.Gold;
            this.UpdateBtn.IdleForecolor = System.Drawing.Color.Black;
            this.UpdateBtn.IdleLineColor = System.Drawing.Color.Gold;
            this.UpdateBtn.Location = new System.Drawing.Point(74, 461);
            this.UpdateBtn.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.UpdateBtn.Name = "UpdateBtn";
            this.UpdateBtn.Size = new System.Drawing.Size(197, 59);
            this.UpdateBtn.TabIndex = 86;
            this.UpdateBtn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.UpdateBtn.Click += new System.EventHandler(this.UpdateBtn_Click);
            // 
            // BackBtn
            // 
            this.BackBtn.ActiveBorderThickness = 1;
            this.BackBtn.ActiveCornerRadius = 20;
            this.BackBtn.ActiveFillColor = System.Drawing.Color.SeaGreen;
            this.BackBtn.ActiveForecolor = System.Drawing.Color.White;
            this.BackBtn.ActiveLineColor = System.Drawing.Color.SeaGreen;
            this.BackBtn.BackColor = System.Drawing.SystemColors.Control;
            this.BackBtn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("BackBtn.BackgroundImage")));
            this.BackBtn.ButtonText = "Back";
            this.BackBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.BackBtn.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.BackBtn.ForeColor = System.Drawing.Color.SeaGreen;
            this.BackBtn.IdleBorderThickness = 1;
            this.BackBtn.IdleCornerRadius = 20;
            this.BackBtn.IdleFillColor = System.Drawing.Color.Gold;
            this.BackBtn.IdleForecolor = System.Drawing.Color.Black;
            this.BackBtn.IdleLineColor = System.Drawing.Color.Gold;
            this.BackBtn.Location = new System.Drawing.Point(816, 461);
            this.BackBtn.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.BackBtn.Name = "BackBtn";
            this.BackBtn.Size = new System.Drawing.Size(213, 59);
            this.BackBtn.TabIndex = 90;
            this.BackBtn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.BackBtn.Click += new System.EventHandler(this.BackBtn_Click);
            // 
            // ViewFlights
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1080, 857);
            this.Controls.Add(this.BackBtn);
            this.Controls.Add(this.ResetBtn);
            this.Controls.Add(this.DeleteBtn);
            this.Controls.Add(this.UpdateBtn);
            this.Controls.Add(this.FlightDGV);
            this.Controls.Add(this.FDate);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.DestiCb);
            this.Controls.Add(this.SrcCb);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.SeatTb);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.FcodeTb);
            this.Controls.Add(this.Label2);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.panel2);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "ViewFlights";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "ViewFlights";
            this.Load += new System.EventHandler(this.ViewFlights_Load);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.FlightDGV)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label label1;
        internal System.Windows.Forms.Button Button2;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.DateTimePicker FDate;
        internal System.Windows.Forms.Label label7;
        private System.Windows.Forms.ComboBox DestiCb;
        private System.Windows.Forms.ComboBox SrcCb;
        internal System.Windows.Forms.Label label4;
        internal System.Windows.Forms.Label label5;
        internal System.Windows.Forms.TextBox SeatTb;
        internal System.Windows.Forms.Label label3;
        internal System.Windows.Forms.TextBox FcodeTb;
        internal System.Windows.Forms.Label Label2;
        internal System.Windows.Forms.DataGridView FlightDGV;
        internal Bunifu.Framework.UI.BunifuThinButton2 ResetBtn;
        internal Bunifu.Framework.UI.BunifuThinButton2 DeleteBtn;
        internal Bunifu.Framework.UI.BunifuThinButton2 UpdateBtn;
        internal Bunifu.Framework.UI.BunifuThinButton2 BackBtn;
    }
}