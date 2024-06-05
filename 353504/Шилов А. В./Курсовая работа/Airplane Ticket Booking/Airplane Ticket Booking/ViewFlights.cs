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
    public partial class ViewFlights : Form
    {
        public ViewFlights()
        {
            InitializeComponent();
        }
        OleDbConnection con = new OleDbConnection(@"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\Users\andre\OneDrive\Рабочий стол\Airplane Ticket Booking\Airplane Ticket Booking\AirlineDb.accdb");

        private void populate()
        {
            con.Open();
            string query = "select * from FlightTbl";
            OleDbDataAdapter sda = new OleDbDataAdapter(query, con);
            OleDbCommandBuilder builder = new OleDbCommandBuilder(sda);
            var ds = new DataSet();
            sda.Fill(ds);
            FlightDGV.DataSource = ds.Tables[0];
            con.Close();
        }
        private void ViewFlights_Load(object sender, EventArgs e)
        {
            populate();
        }

        private void BackBtn_Click(object sender, EventArgs e)
        {
            Flight fli = new Flight();
            fli.Show();
            this.Hide();
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void ResetBtn_Click(object sender, EventArgs e)
        {
            FcodeTb.Text = "";
            SrcCb.Text = "";
            DestiCb.Text = "";
            FDate.Text = "";
            SeatTb.Text = "";
        }

        private void FlightDGV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            FcodeTb.Text = FlightDGV.SelectedRows[0].Cells[0].Value.ToString();
            SrcCb.Text = FlightDGV.SelectedRows[0].Cells[1].Value.ToString();           
            DestiCb.Text = FlightDGV.SelectedRows[0].Cells[2].Value.ToString();
            FDate.Text = FlightDGV.SelectedRows[0].Cells[3].Value.ToString();
            SeatTb.Text = FlightDGV.SelectedRows[0].Cells[4].Value.ToString();

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void FDate_ValueChanged(object sender, EventArgs e)
        {

        }

        private void DeleteBtn_Click(object sender, EventArgs e)
        {
            if (FcodeTb.Text == "")
            {
                MessageBox.Show("enter the Flight to delete");

            }
            else
            {
                try
                {
                    con.Open();
                    string query = "delete from FlightTbl where FCode='" + FcodeTb.Text + "';";
                    OleDbCommand cmd = new OleDbCommand(query, con);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("Flight Deleted successfully");
                    con.Close();
                    populate();
                }
                catch (Exception Ex)
                {
                    MessageBox.Show(Ex.Message);
                }

            }
        }

        private void UpdateBtn_Click(object sender, EventArgs e)
        {
            if (FcodeTb.Text == "" || SeatTb.Text == "" )
            {
                MessageBox.Show("Missing Information");
            }
            else
            {
                try
                {
                    con.Open();
                    string query = "update FlightTbl set Fsrc='" + SrcCb.SelectedItem.ToString() + "',Fdest='" + DestiCb.SelectedItem.ToString() + "',FDate= '"+ FDate.Value.Date.ToString() + "',FSeat=" +SeatTb.Text + " where Fcode='" + FcodeTb.Text + "';";
                    OleDbCommand cmd = new OleDbCommand(query, con);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("Flight Update Successfully");
                    con.Close();
                    populate();
                }
                catch (Exception Ex)
                {
                    MessageBox.Show(Ex.Message);
                }
            }
        }
    }
}
