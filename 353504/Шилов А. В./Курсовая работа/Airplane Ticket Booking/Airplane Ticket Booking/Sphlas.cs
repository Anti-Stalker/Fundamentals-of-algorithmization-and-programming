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
    public partial class Sphlas : Form
    {
        public Sphlas()
        {
            InitializeComponent();
        }
        int startpoint = 0;
        private void timer1_Tick(object sender, EventArgs e)
        {
            startpoint += 1;
            Progress.Value = startpoint;
            if (Progress.Value == 100)
            {
                Progress.Value = 0;
                timer1.Stop();
                Login log = new Login();
                log.Show();
                this.Hide();
            }
        }

        private void Sphlas_Load(object sender, EventArgs e)
        {
            timer1.Start();
        }
    }
}
