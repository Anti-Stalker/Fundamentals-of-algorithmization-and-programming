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
    public partial class View_Passanger : Form
    {
        public View_Passanger()
        {
            InitializeComponent();
        }
        OleDbConnection con = new OleDbConnection(@"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\Users\andre\OneDrive\Рабочий стол\Airplane Ticket Booking\Airplane Ticket Booking\AirlineDb.accdb");
        private void populate()
        {
            con.Open();
            string query = "select * from PassangerTbl";
            OleDbDataAdapter sda = new OleDbDataAdapter(query, con);
            OleDbCommandBuilder builder = new OleDbCommandBuilder(sda);
            var ds=new DataSet() ;
            sda.Fill(ds);
            PassangerDGV.DataSource = ds.Tables[0];
            con.Close();
        }
        private void View_Passanger_Load(object sender, EventArgs e)
        {
            populate();
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void BackBtn_Click(object sender, EventArgs e)
        {
            Passanger addpass = new Passanger();
            addpass.Show();
            this.Hide();
        }

        private void ResetBtn_Click(object sender, EventArgs e)
        {
            Pid.Text="";
            Pname.Text = "";
            Ppassport.Text = "";
            Padd.Text = "";
            NatCb.Text = "";
            GenCb.Text = "";
            PhoneTb.Text = "";
        }

        private void DeleteBtn_Click(object sender, EventArgs e)
        {
            if (Pid.Text == "")
            {
                MessageBox.Show("enter the pasanger to delete");

            }
            else {
                try
                {
                    con.Open();
                    string query = "delete from PassangerTbl where PassId=" + Pid.Text + ";";
                    OleDbCommand cmd = new OleDbCommand(query, con);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("Passanger Deleted successfull");
                    con.Close();
                    populate();
                }
                catch (Exception Ex)
                {
                    MessageBox.Show(Ex.Message);
                }
            
            }
        }

        private void PassangerDGV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            Pid.Text = PassangerDGV.SelectedRows[0].Cells[0].Value.ToString();
            Pname.Text = PassangerDGV.SelectedRows[0].Cells[1].Value.ToString();
            Ppassport.Text = PassangerDGV.SelectedRows[0].Cells[2].Value.ToString();
            Padd.Text = PassangerDGV.SelectedRows[0].Cells[3].Value.ToString();
            NatCb.Text = PassangerDGV.SelectedRows[0].Cells[4].Value.ToString();
            GenCb.Text = PassangerDGV.SelectedRows[0].Cells[5].Value.ToString();
            PhoneTb.Text = PassangerDGV.SelectedRows[0].Cells[6].Value.ToString();
        }

        private void UpdateBtn_Click(object sender, EventArgs e)
        {
            if (Pid.Text == "" || Pname.Text == "" || Ppassport.Text == "" || Padd.Text == "")
            {
                MessageBox.Show("Missing Information");
            }
            else {
                try
                {
                    con.Open();
                    string query = "update PassangerTbl set PassName='" + Pname.Text + "',Passport='" + Ppassport.Text + "',PassAd='" + Padd.Text + "',PassNat='" + NatCb .SelectedItem.ToString() + "',PassGend='" + GenCb .SelectedItem.ToString() + "',PassPhone='" + PhoneTb.Text + "' where PassId=" + Pid.Text + ";";
                    OleDbCommand cmd = new OleDbCommand(query, con);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("Passanger Update Successfully");
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
