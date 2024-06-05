using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Airplane_Ticket_Booking
{
    public partial class Login : Form
    {
        public Login()
        {
            InitializeComponent();
        }

        private void Login_Load(object sender, EventArgs e)
        {

        }

        private void Button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void ResetLbl_Click(object sender, EventArgs e)
        {
            UNameTb.Text = "";
            PassTb.Text = "";
        }

        private void LoginBtn_Click(object sender, EventArgs e)
        {
            if (UNameTb.Text == "" || PassTb.Text == "")
            {
                MessageBox.Show("Enter the User Name & Password");
            }
            else if (UNameTb.Text == "Admin" && PassTb.Text == "Admin123")
            {
                Home home = new Home();
                home.Show();
                this.Hide();
            }
            else
            {
                MessageBox.Show("Wrong UserName & Password");
            
            }
            
            
        }
    }
}
