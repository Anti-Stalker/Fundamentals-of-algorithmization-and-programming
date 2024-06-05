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
    public partial class Flight : Form
    {
        public Flight()
        {
            InitializeComponent();
        }
        OleDbConnection con = new OleDbConnection(@"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\Users\andre\OneDrive\Рабочий стол\Airplane Ticket Booking\Airplane Ticket Booking\AirlineDb.accdb");

        private void Button2_Click(object sender, EventArgs e)
        {
            Application.Exit();

        }

        private void RecordBtn_Click(object sender, EventArgs e)
        {
            if (FCodeTb.Text == "" || NumSeatTb.Text == "")
            {
                MessageBox.Show("Missing Information");
            }
            else
            {
                try
                {
                    con.Open();
                    string query = "insert into FlightTbl values ('" + FCodeTb.Text + "','" + SourceCb.SelectedItem.ToString() + "','" + DestinationCb.SelectedItem.ToString() + "','" + DateDtp.Value.Date + "'," + NumSeatTb.Text + ")";
                    OleDbCommand cmd = new OleDbCommand(query, con);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("Passanger Recorded SuccessFully");
                    con.Close();

                }
                catch (Exception Ex)
                {
                    MessageBox.Show(Ex.Message);
                }

            }
        }

        private void ResetBtn_Click(object sender, EventArgs e)
        {
            FCodeTb.Text = "";
            SourceCb.Text = "";
            DestinationCb.Text = "";
            DateDtp.Text = "";
            NumSeatTb.Text = "";
        }

        private void ViewFlightBtn_Click(object sender, EventArgs e)
        {
            ViewFlights viewfli = new ViewFlights ();
            viewfli.Show();
            this.Hide();
        }

        private void Flight_Load(object sender, EventArgs e)
        {

        }

        private void Backbtn_Click(object sender, EventArgs e)
        {
            Home home = new Home();
            home.Show();
            this.Hide();
        }

        private void FCodeTb_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
