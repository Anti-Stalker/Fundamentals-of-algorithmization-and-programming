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
    public partial class CancelationTbl : Form
    {
        public CancelationTbl()
        {
            InitializeComponent();
        }
        OleDbConnection con = new OleDbConnection(@"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\Users\andre\OneDrive\Рабочий стол\Airplane Ticket Booking\Airplane Ticket Booking\AirlineDb.accdb");
        private void populate()
        {
            con.Open();
            string query = "select * from CancleTbl";
            OleDbDataAdapter sda = new OleDbDataAdapter(query, con);
            OleDbCommandBuilder builder = new OleDbCommandBuilder(sda);
            var ds = new DataSet();
            sda.Fill(ds);
            CancleDGV.DataSource = ds.Tables[0];
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
        private void fillTicketId()
        {
            con.Open();
            OleDbCommand cmd = new OleDbCommand("select TId from TicketTbl", con);
            OleDbDataReader rdr;
            rdr = cmd.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Columns.Add("TId", typeof(int));
            dt.Load(rdr);
            TIdCb.ValueMember = "TId";
            TIdCb.DataSource = dt;
            con.Close();
        }
        private void fetchFcode()
        {
            con.Open();
            string query = "select * from TicketTbl whereTId=" + TIdCb.SelectedValue.ToString() + ";";
            OleDbCommand cmd = new OleDbCommand(query, con);
            DataTable dt = new DataTable();
            OleDbDataAdapter da = new OleDbDataAdapter(cmd);
            da.Fill(dt);
            foreach (DataRow dr in dt.Rows)
            {
                FcodeCb.Text = dr["Fcode"].ToString();
                
            }

            con.Close();
        }
        private void deleteTicket()
        {

            try
            {
                con.Open();
                string query = "delete from TicketTbl where TId=" + TIdCb.SelectedValue.ToString() + ";";
                OleDbCommand cmd = new OleDbCommand(query, con);
                cmd.ExecuteNonQuery();
                MessageBox.Show("Ticket Deleted successfully");
                con.Close();
                populate();
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message);
            }

        }
        
        private void CancelBtn_Click(object sender, EventArgs e)
        {
            if (CanclTb.Text == "" || FcodeCb .Text=="")
            {
                MessageBox.Show("Missing Information");
            }
            else
            {
                try
                {
                    con.Open();
                    string query = "insert into CancleTbl values (" + CanclTb.Text + ",'" + TIdCb.SelectedValue.ToString() + "','" + FcodeCb.SelectedValue.ToString() + "','" + DateDtp.Value .Date + "')";
                    OleDbCommand cmd = new OleDbCommand(query, con);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("Ticket Canceled SuccessFully");
                    con.Close();
                    populate();
                    deleteTicket();
                    
                    

                }
                catch (Exception Ex)
                {
                    MessageBox.Show(Ex.Message);
                    con.Close();
                }

            }
        }

        private void CancelationTbl_Load(object sender, EventArgs e)
        {
            populate();
            fillFlightCode();
            fillTicketId();
            
            
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void clearBtn_Click(object sender, EventArgs e)
        {
            CanclTb.Text = "";
            TIdCb.Text = "";
            FcodeCb.Text = "";
            DateDtp.Text = "";
        }

        private void CancleDGV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            string canclTbText = CancleDGV.SelectedRows[0].Cells[0].Value.ToString();
            string tIdCbText = CancleDGV.SelectedRows[0].Cells[1].Value.ToString();
            string fcodeCbText = CancleDGV.SelectedRows[0].Cells[2].Value.ToString();
            string dateDtpText = CancleDGV.SelectedRows[0].Cells[3].Value.ToString();
        }

        private void BackBtn_Click(object sender, EventArgs e)
        {
            Home home = new Home();
            home.Show();
            this.Hide();
        }

        private void CanclTb_TextChanged(object sender, EventArgs e)
        {

        }

        private void TIdCb_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
    
}
