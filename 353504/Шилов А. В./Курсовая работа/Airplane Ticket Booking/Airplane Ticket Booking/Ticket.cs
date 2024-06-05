using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.OleDb;

namespace Airplane_Ticket_Booking
{
    public partial class Ticket : Form
    {
        public Ticket()
        {
            InitializeComponent();
        }
        OleDbConnection con = new OleDbConnection(@"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\Users\andre\OneDrive\Рабочий стол\Airplane Ticket Booking\Airplane Ticket Booking\AirlineDb.accdb");
        private void populate()
        {
            con.Open();
            string query = "select * from TicketTbl";
            OleDbDataAdapter sda = new OleDbDataAdapter(query, con);
            OleDbCommandBuilder builder = new OleDbCommandBuilder(sda);
            var ds = new DataSet();
            sda.Fill(ds);
            TicketDGV.DataSource = ds.Tables[0];
            con.Close();
        }
        private void fillpassanger()
        {
            con.Open();
            OleDbCommand cmd = new OleDbCommand("select PassId from PassangerTbl",con);
            OleDbDataReader rdr;
            rdr = cmd.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Columns.Add("PassId", typeof(int));
            dt.Load(rdr);
            PassIdCb.ValueMember = "PassId";
            PassIdCb.DataSource = dt;
            con.Close();
        }

        private void fillFlightCode()
        {
            con.Open();
            OleDbCommand cmd = new OleDbCommand("select FCode from FlightTbl", con);
            OleDbDataReader rdr;
            rdr = cmd.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Columns.Add("FCode", typeof(string));
            dt.Load(rdr);
            FcodeCb.ValueMember = "FCode";
            FcodeCb.DataSource = dt;
            con.Close();
        }

        private void fetchpassanger()
        {
            con.Open();
            string query = "select * from PassangerTbl where PassId=" + PassIdCb.SelectedValue.ToString() + ";";
            OleDbCommand cmd = new OleDbCommand(query, con);
            DataTable dt = new DataTable();
            OleDbDataAdapter da = new OleDbDataAdapter(cmd);
            da.Fill(dt);
            foreach (DataRow dr in dt.Rows)
            {
                pname = dr["PassName"].ToString();
                ppass = dr["Passport"].ToString();
                pnat = dr["PassNat"].ToString();
                NameTb.Text = pname;
                PassportTb.Text = ppass;
                NatTb.Text = pnat;
            }

            con.Close();
        }
        private void Button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void BookBtn_Click(object sender, EventArgs e)
        {
             if (TIdTb.Text == "" || AmountTb.Text == "")
            {
                MessageBox.Show("Missing Information");
            }
            else
            {
                try
                {
                    con.Open();
                    string query = "insert into TicketTbl values (" + TIdTb.Text + ",'" + FcodeCb.SelectedValue.ToString() + "','" + PassIdCb.SelectedValue.ToString() + "','" + NameTb.Text + "','" + PassportTb.Text + "','" + NatTb.Text + "','" + AmountTb.Text + "')";
                    OleDbCommand cmd = new OleDbCommand(query, con);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("Ticket Booked SuccessFully");
                    con.Close();
                    populate();
                }
                catch (Exception Ex)
                {
                    MessageBox.Show(Ex.Message);
                }

            }
        }
        private void Ticket_Load(object sender, EventArgs e)
        {
            populate();
            fillpassanger();
            fillFlightCode();
            fetchpassanger();
            
        }
        string pname, ppass, pnat;
      
        private void PassIdCb_SelectionChangeCommitted(object sender, EventArgs e)
        {
            fetchpassanger();
        }

        private void TicketDGV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            TIdTb.Text = TicketDGV.SelectedRows[0].Cells[0].Value.ToString();
            FcodeCb.SelectedValue = TicketDGV.SelectedRows[0].Cells[1].Value.ToString();
            PassIdCb.SelectedValue = TicketDGV.SelectedRows[0].Cells[2].Value.ToString();
            NameTb .Text=TicketDGV.SelectedRows[0].Cells[3].Value.ToString();
            PassportTb .Text=TicketDGV.SelectedRows[0].Cells[4].Value.ToString();
            NatTb.Text = TicketDGV.SelectedRows[0].Cells[5].Value.ToString();
            AmountTb.Text = TicketDGV.SelectedRows[0].Cells[6].Value.ToString();
        }

        private void FcodeCb_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void ResetBtn_Click(object sender, EventArgs e)
        {
            TIdTb.Text="";
            NameTb.Text="";
            PassportTb.Text ="";
            NatTb.Text="";
            AmountTb.Text = "";
        }

        private void BackBtn_Click(object sender, EventArgs e)
        {
            Home home = new Home();
            home.Show();
            this.Hide();
        }

        
    }
}
