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
    public partial class Passanger : Form
   {
        public Passanger()
        {
            InitializeComponent();
        }
        OleDbConnection con = new OleDbConnection(@"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\Users\andre\OneDrive\Рабочий стол\Airplane Ticket Booking\Airplane Ticket Booking\AirlineDb.accdb");
        private void Button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Passanger_Load(object sender, EventArgs e)
        {
            this.passangerTblTableAdapter.Fill(this.airlineDbDataSet.PassangerTbl);

        }

        private void RecordBtn_Click(object sender, EventArgs e)
        {
            if (PassId.Text == "" || PassName.Text == "" || PassportTb.Text == "" || PassAd.Text == "" || PhoneTb.Text == "")
            {
                MessageBox.Show("Missing Information");
            }
            else
            {
                try
                {
                    con.Open();
                    string query = "insert into PassangerTbl values ('" + PassId.Text + "','" + PassName.Text + "','" + PassportTb.Text + "','" + PassAd.Text + "','" + NationalityCb.SelectedItem.ToString() + "','" + GenderCb.SelectedItem.ToString() + "','" + PhoneTb.Text + "')";
                    OleDbCommand cmd = new OleDbCommand(query, con);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("Passanger Recorded SuccessFully");
                    con.Close();

                }
                catch (Exception Ex)
                {
                    MessageBox.Show(Ex.Message);
                    con.Close();
                }
            
            }
        }

        private void ViewPassngrBtn_Click(object sender, EventArgs e)
        {
            View_Passanger viewpass=new View_Passanger ();
            viewpass.Show();
            this.Hide();
        }

        private void ResetBtn_Click(object sender, EventArgs e)
        {
            PassId.Text = "";
            PassName.Text = "";
            PassportTb.Text = "";
            PassAd.Text = "";
            NationalityCb.Text = "";
            GenderCb.Text = "";
            PhoneTb.Text = "";


        }

        private void Backbtn_Click(object sender, EventArgs e)
        {
            Home home = new Home();
            home.Show();
            this.Hide();
        }

        private void PassName_TextChanged(object sender, EventArgs e)
        {

        }

        private void PassId_TextChanged(object sender, EventArgs e)
        {

        }
    }
}

