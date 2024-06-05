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
    public partial class Home : Form
    {
        public Home()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Flightbtn_Click(object sender, EventArgs e)
        {
            Flight fli = new Flight();
            fli.Show();
            this.Hide();
        }

        private void Passangerbtn_Click(object sender, EventArgs e)
        {
            Passanger  Pass = new Passanger ();
            Pass.Show();
            this.Hide();
        }

        private void TicketBtn_Click(object sender, EventArgs e)
        {
            Ticket Tick = new Ticket ();
            Tick.Show();
            this.Hide();
        }

        private void CanceletionBtn_Click(object sender, EventArgs e)
        {
            CancelationTbl can = new CancelationTbl ();
            can.Show();
            this.Hide();
        }
    }
}
