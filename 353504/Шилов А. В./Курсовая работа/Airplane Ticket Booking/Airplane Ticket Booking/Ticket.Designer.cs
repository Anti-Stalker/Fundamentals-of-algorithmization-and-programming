namespace Airplane_Ticket_Booking
{
    partial class Ticket
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
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle3 = new System.Windows.Forms.DataGridViewCellStyle();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Ticket));
            this.TicketDGV = new System.Windows.Forms.DataGridView();
            this.FcodeCb = new System.Windows.Forms.ComboBox();
            this.PassIdCb = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.NameTb = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.PassportTb = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.TIdTb = new System.Windows.Forms.TextBox();
            this.Label2 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.NatTb = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.Button2 = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.AmountTb = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.BackBtn = new Bunifu.Framework.UI.BunifuThinButton2();
            this.ResetBtn = new Bunifu.Framework.UI.BunifuThinButton2();
            this.BookBtn = new Bunifu.Framework.UI.BunifuThinButton2();
            this.label11 = new System.Windows.Forms.Label();
            this.airlineDbDataSet = new Airplane_Ticket_Booking.AirlineDbDataSet();
            this.ticketTblBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.ticketTblTableAdapter = new Airplane_Ticket_Booking.AirlineDbDataSetTableAdapters.TicketTblTableAdapter();
            ((System.ComponentModel.ISupportInitialize)(this.TicketDGV)).BeginInit();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.airlineDbDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ticketTblBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // TicketDGV
            // 
            this.TicketDGV.AllowUserToAddRows = false;
            this.TicketDGV.AllowUserToOrderColumns = true;
            this.TicketDGV.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.TicketDGV.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.DisplayedCells;
            this.TicketDGV.BackgroundColor = System.Drawing.Color.White;
            this.TicketDGV.CellBorderStyle = System.Windows.Forms.DataGridViewCellBorderStyle.None;
            this.TicketDGV.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.None;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle1.BackColor = System.Drawing.Color.Navy;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle1.ForeColor = System.Drawing.Color.White;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.Color.Navy;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.Color.Lavender;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.TicketDGV.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this.TicketDGV.ColumnHeadersHeight = 28;
            this.TicketDGV.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.DisableResizing;
            this.TicketDGV.Cursor = System.Windows.Forms.Cursors.Default;
            dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle2.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle2.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle2.SelectionBackColor = System.Drawing.Color.Gold;
            dataGridViewCellStyle2.SelectionForeColor = System.Drawing.Color.DarkBlue;
            dataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.TicketDGV.DefaultCellStyle = dataGridViewCellStyle2;
            this.TicketDGV.EnableHeadersVisualStyles = false;
            this.TicketDGV.GridColor = System.Drawing.Color.White;
            this.TicketDGV.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.TicketDGV.Location = new System.Drawing.Point(11, 620);
            this.TicketDGV.Name = "TicketDGV";
            this.TicketDGV.ReadOnly = true;
            dataGridViewCellStyle3.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle3.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle3.Font = new System.Drawing.Font("Century Gothic", 14.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle3.ForeColor = System.Drawing.SystemColors.Info;
            dataGridViewCellStyle3.SelectionBackColor = System.Drawing.Color.Gold;
            dataGridViewCellStyle3.SelectionForeColor = System.Drawing.Color.DarkBlue;
            dataGridViewCellStyle3.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.TicketDGV.RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
            this.TicketDGV.RowHeadersWidth = 62;
            this.TicketDGV.RowTemplate.Height = 24;
            this.TicketDGV.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.TicketDGV.Size = new System.Drawing.Size(1056, 234);
            this.TicketDGV.TabIndex = 103;
            this.TicketDGV.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.TicketDGV_CellContentClick);
            // 
            // FcodeCb
            // 
            this.FcodeCb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FcodeCb.FormattingEnabled = true;
            this.FcodeCb.Location = new System.Drawing.Point(752, 234);
            this.FcodeCb.Name = "FcodeCb";
            this.FcodeCb.Size = new System.Drawing.Size(283, 35);
            this.FcodeCb.TabIndex = 102;
            this.FcodeCb.SelectedIndexChanged += new System.EventHandler(this.FcodeCb_SelectedIndexChanged);
            // 
            // PassIdCb
            // 
            this.PassIdCb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PassIdCb.FormattingEnabled = true;
            this.PassIdCb.Location = new System.Drawing.Point(221, 299);
            this.PassIdCb.Name = "PassIdCb";
            this.PassIdCb.Size = new System.Drawing.Size(283, 35);
            this.PassIdCb.TabIndex = 101;
            this.PassIdCb.SelectionChangeCommitted += new System.EventHandler(this.PassIdCb_SelectionChangeCommitted);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BackColor = System.Drawing.SystemColors.Control;
            this.label8.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label8.Location = new System.Drawing.Point(560, 359);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(164, 34);
            this.label8.TabIndex = 100;
            this.label8.Text = "Nationality";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.BackColor = System.Drawing.SystemColors.Control;
            this.label9.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label9.Location = new System.Drawing.Point(26, 359);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(128, 34);
            this.label9.TabIndex = 99;
            this.label9.Text = "Passport";
            // 
            // NameTb
            // 
            this.NameTb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.NameTb.Location = new System.Drawing.Point(752, 299);
            this.NameTb.Name = "NameTb";
            this.NameTb.Size = new System.Drawing.Size(283, 36);
            this.NameTb.TabIndex = 96;
            this.NameTb.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.SystemColors.Control;
            this.label5.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label5.Location = new System.Drawing.Point(560, 232);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(174, 34);
            this.label5.TabIndex = 95;
            this.label5.Text = "Flight Code";
            // 
            // PassportTb
            // 
            this.PassportTb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PassportTb.Location = new System.Drawing.Point(221, 361);
            this.PassportTb.Name = "PassportTb";
            this.PassportTb.Size = new System.Drawing.Size(283, 36);
            this.PassportTb.TabIndex = 94;
            this.PassportTb.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.SystemColors.Control;
            this.label4.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label4.Location = new System.Drawing.Point(19, 297);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(187, 34);
            this.label4.TabIndex = 93;
            this.label4.Text = "Passanger Id";
            // 
            // TIdTb
            // 
            this.TIdTb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TIdTb.Location = new System.Drawing.Point(221, 234);
            this.TIdTb.Name = "TIdTb";
            this.TIdTb.Size = new System.Drawing.Size(283, 36);
            this.TIdTb.TabIndex = 90;
            // 
            // Label2
            // 
            this.Label2.AutoSize = true;
            this.Label2.BackColor = System.Drawing.SystemColors.Control;
            this.Label2.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Label2.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.Label2.Location = new System.Drawing.Point(19, 232);
            this.Label2.Name = "Label2";
            this.Label2.Size = new System.Drawing.Size(126, 34);
            this.Label2.TabIndex = 89;
            this.Label2.Text = "Ticket Id";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Century", 22.2F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Italic | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.Navy;
            this.label6.Location = new System.Drawing.Point(406, 148);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(279, 44);
            this.label6.TabIndex = 88;
            this.label6.Text = "Ticket Booking";
            // 
            // NatTb
            // 
            this.NatTb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.NatTb.Location = new System.Drawing.Point(752, 361);
            this.NatTb.Name = "NatTb";
            this.NatTb.Size = new System.Drawing.Size(283, 36);
            this.NatTb.TabIndex = 92;
            this.NatTb.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.SystemColors.Control;
            this.label3.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label3.Location = new System.Drawing.Point(550, 297);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(107, 34);
            this.label3.TabIndex = 91;
            this.label3.Text = " Name";
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.Navy;
            this.panel2.Controls.Add(this.label1);
            this.panel2.Controls.Add(this.Button2);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(1079, 122);
            this.panel2.TabIndex = 87;
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
            this.panel1.Location = new System.Drawing.Point(0, 865);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1079, 17);
            this.panel1.TabIndex = 104;
            // 
            // AmountTb
            // 
            this.AmountTb.Font = new System.Drawing.Font("Century Gothic", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AmountTb.Location = new System.Drawing.Point(451, 427);
            this.AmountTb.Name = "AmountTb";
            this.AmountTb.Size = new System.Drawing.Size(283, 36);
            this.AmountTb.TabIndex = 106;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.BackColor = System.Drawing.SystemColors.Control;
            this.label10.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label10.Location = new System.Drawing.Point(287, 425);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(124, 34);
            this.label10.TabIndex = 105;
            this.label10.Text = "Amount";
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
            this.BackBtn.Location = new System.Drawing.Point(707, 497);
            this.BackBtn.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.BackBtn.Name = "BackBtn";
            this.BackBtn.Size = new System.Drawing.Size(213, 59);
            this.BackBtn.TabIndex = 109;
            this.BackBtn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.BackBtn.Click += new System.EventHandler(this.BackBtn_Click);
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
            this.ResetBtn.Location = new System.Drawing.Point(414, 497);
            this.ResetBtn.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.ResetBtn.Name = "ResetBtn";
            this.ResetBtn.Size = new System.Drawing.Size(213, 59);
            this.ResetBtn.TabIndex = 108;
            this.ResetBtn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.ResetBtn.Click += new System.EventHandler(this.ResetBtn_Click);
            // 
            // BookBtn
            // 
            this.BookBtn.ActiveBorderThickness = 1;
            this.BookBtn.ActiveCornerRadius = 20;
            this.BookBtn.ActiveFillColor = System.Drawing.Color.SeaGreen;
            this.BookBtn.ActiveForecolor = System.Drawing.Color.White;
            this.BookBtn.ActiveLineColor = System.Drawing.Color.SeaGreen;
            this.BookBtn.BackColor = System.Drawing.SystemColors.Control;
            this.BookBtn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("BookBtn.BackgroundImage")));
            this.BookBtn.ButtonText = "Book";
            this.BookBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.BookBtn.Font = new System.Drawing.Font("Century Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.BookBtn.ForeColor = System.Drawing.Color.SeaGreen;
            this.BookBtn.IdleBorderThickness = 1;
            this.BookBtn.IdleCornerRadius = 20;
            this.BookBtn.IdleFillColor = System.Drawing.Color.Gold;
            this.BookBtn.IdleForecolor = System.Drawing.Color.Black;
            this.BookBtn.IdleLineColor = System.Drawing.Color.Gold;
            this.BookBtn.Location = new System.Drawing.Point(146, 497);
            this.BookBtn.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.BookBtn.Name = "BookBtn";
            this.BookBtn.Size = new System.Drawing.Size(197, 59);
            this.BookBtn.TabIndex = 107;
            this.BookBtn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.BookBtn.Click += new System.EventHandler(this.BookBtn_Click);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Century", 22.2F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Italic | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label11.ForeColor = System.Drawing.Color.Navy;
            this.label11.Location = new System.Drawing.Point(406, 562);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(239, 44);
            this.label11.TabIndex = 110;
            this.label11.Text = "Booking List";
            // 
            // airlineDbDataSet
            // 
            this.airlineDbDataSet.DataSetName = "AirlineDbDataSet";
            this.airlineDbDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // ticketTblBindingSource
            // 
            this.ticketTblBindingSource.DataMember = "TicketTbl";
            this.ticketTblBindingSource.DataSource = this.airlineDbDataSet;
            // 
            // ticketTblTableAdapter
            // 
            this.ticketTblTableAdapter.ClearBeforeFill = true;
            // 
            // Ticket
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1079, 882);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.BackBtn);
            this.Controls.Add(this.ResetBtn);
            this.Controls.Add(this.BookBtn);
            this.Controls.Add(this.AmountTb);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.TicketDGV);
            this.Controls.Add(this.FcodeCb);
            this.Controls.Add(this.PassIdCb);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.NameTb);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.PassportTb);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.TIdTb);
            this.Controls.Add(this.Label2);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.NatTb);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.panel2);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Ticket";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Ticket";
            this.Load += new System.EventHandler(this.Ticket_Load);
            ((System.ComponentModel.ISupportInitialize)(this.TicketDGV)).EndInit();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.airlineDbDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ticketTblBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        internal System.Windows.Forms.DataGridView TicketDGV;
        private System.Windows.Forms.ComboBox FcodeCb;
        private System.Windows.Forms.ComboBox PassIdCb;
        internal System.Windows.Forms.Label label8;
        internal System.Windows.Forms.Label label9;
        internal System.Windows.Forms.TextBox NameTb;
        internal System.Windows.Forms.Label label5;
        internal System.Windows.Forms.TextBox PassportTb;
        internal System.Windows.Forms.Label label4;
        internal System.Windows.Forms.TextBox TIdTb;
        internal System.Windows.Forms.Label Label2;
        private System.Windows.Forms.Label label6;
        internal System.Windows.Forms.TextBox NatTb;
        internal System.Windows.Forms.Label label3;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label label1;
        internal System.Windows.Forms.Button Button2;
        private System.Windows.Forms.Panel panel1;
        internal System.Windows.Forms.TextBox AmountTb;
        internal System.Windows.Forms.Label label10;
        internal Bunifu.Framework.UI.BunifuThinButton2 BackBtn;
        internal Bunifu.Framework.UI.BunifuThinButton2 ResetBtn;
        internal Bunifu.Framework.UI.BunifuThinButton2 BookBtn;
        private System.Windows.Forms.Label label11;
        private AirlineDbDataSet airlineDbDataSet;
        private System.Windows.Forms.BindingSource ticketTblBindingSource;
        private AirlineDbDataSetTableAdapters.TicketTblTableAdapter ticketTblTableAdapter;
    }
}