using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HDesk63IPCalc
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void bt_calculer_Click(object sender, EventArgs e)
        {
            Int16 numBase;
            Int16 dec1;
            Int16 dec2;
            Int16 dec3;
            Int16 dec4;
            string bin1;
            string bin2;
            string bin3;
            string bin4;

            numBase = 2;
            dec1 = Int16.Parse(tx_ipde1.Text);
            dec2 = Int16.Parse(tx_ipde2.Text);
            dec3 = Int16.Parse(tx_ipde3.Text);
            dec4 = Int16.Parse(tx_ipde4.Text);

            bin1 = Convert.ToString(dec1, numBase);
            bin2 = Convert.ToString(dec2, numBase);
            bin3 = Convert.ToString(dec3, numBase);
            bin4 = Convert.ToString(dec4, numBase);

            tx_ipbi1.Text = bin1;
            tx_ipbi2.Text = bin2;
            tx_ipbi3.Text = bin3;
            tx_ipbi4.Text = bin4;

            tx_masquebi1.Text = "";
            tx_masquebi2.Text = "";
            tx_masquebi3.Text = "";
            tx_masquebi4.Text = "";

            int nbdebit;
            nbdebit = 8;
            int cidr;

            cidr = int.Parse(tx_cidr.Text);

            while (nbdebit != 0)
            {
                if (cidr > 0)
                {
                    tx_masquebi1.Text = tx_masquebi1.Text + "1";
                    cidr = cidr - 1;
                    nbdebit = nbdebit - 1;
                }
                else if (cidr <= 0)
                {
                    tx_masquebi1.Text = tx_masquebi1.Text + "0";
                    nbdebit = nbdebit - 1;
                }
            }

            nbdebit = 8;

            while (nbdebit != 0)
            {
                if (cidr > 0)
                {
                    tx_masquebi2.Text = tx_masquebi2.Text + "1";
                    cidr = cidr - 1;
                    nbdebit = nbdebit - 1;
                }
                else if (cidr <= 0)
                {
                    tx_masquebi2.Text = tx_masquebi2.Text + "0";
                    nbdebit = nbdebit - 1;
                }
            }

            nbdebit = 8;

            while (nbdebit != 0)
            {
                if (cidr > 0)
                {
                    tx_masquebi3.Text = tx_masquebi3.Text + "1";
                    cidr = cidr - 1;
                    nbdebit = nbdebit - 1;
                }
                else if (cidr <= 0)
                {
                    tx_masquebi3.Text = tx_masquebi3.Text + "0";
                    nbdebit = nbdebit - 1;
                }
            }

            nbdebit = 8;

            while (nbdebit != 0)
            {
                if (cidr > 0)
                {
                    tx_masquebi4.Text = tx_masquebi4.Text + "1";
                    cidr = cidr - 1;
                    nbdebit = nbdebit - 1;
                }
                else if (cidr <= 0)
                {
                    tx_masquebi4.Text = tx_masquebi4.Text + "0";
                    nbdebit = nbdebit - 1;
                }
            }

            string binmasque1;
            string binmasque2;
            string binmasque3;
            string binmasque4;
            byte decmasque1;
            byte decmasque2;
            byte decmasque3;
            byte decmasque4;

            binmasque1 = tx_masquebi1.Text;
            binmasque2 = tx_masquebi2.Text;
            binmasque3 = tx_masquebi3.Text;
            binmasque4 = tx_masquebi4.Text;

            decmasque1 = Convert.ToByte(binmasque1, numBase);
            decmasque2 = Convert.ToByte(binmasque2, numBase);
            decmasque3 = Convert.ToByte(binmasque3, numBase);
            decmasque4 = Convert.ToByte(binmasque4, numBase);

            tx_masquede1.Text = Convert.ToString(decmasque1);
            tx_masquede2.Text = Convert.ToString(decmasque2);
            tx_masquede3.Text = Convert.ToString(decmasque3);
            tx_masquede4.Text = Convert.ToString(decmasque4);
        }

        private void tx_ipde1_TextChanged(object sender, EventArgs e)
        {
            if (tx_ipde1.Text != "" && tx_ipde2.Text != "" && tx_ipde3.Text != "" && tx_ipde4.Text != "" && tx_cidr.Text != "")
            {
                bt_calculer.Enabled = true;
            }
            else
            {
                bt_calculer.Enabled = false;
            }
        }

        private void tx_ipde2_TextChanged(object sender, EventArgs e)
        {
            if (tx_ipde1.Text != "" && tx_ipde2.Text != "" && tx_ipde3.Text != "" && tx_ipde4.Text != "" && tx_cidr.Text != "")
            {
                bt_calculer.Enabled = true;
            }
            else
            {
                bt_calculer.Enabled = false;
            }
        }

        private void tx_ipde3_TextChanged(object sender, EventArgs e)
        {
            if (tx_ipde1.Text != "" && tx_ipde2.Text != "" && tx_ipde3.Text != "" && tx_ipde4.Text != "" && tx_cidr.Text != "")
            {
                bt_calculer.Enabled = true;
            }
            else
            {
                bt_calculer.Enabled = false;
            }
        }

        private void tx_ipde4_TextChanged(object sender, EventArgs e)
        {
            if (tx_ipde1.Text != "" && tx_ipde2.Text != "" && tx_ipde3.Text != "" && tx_ipde4.Text != "" && tx_cidr.Text != "")
            {
                bt_calculer.Enabled = true;
            }
            else
            {
                bt_calculer.Enabled = false;
            }
        }

        private void tx_cidr_TextChanged(object sender, EventArgs e)
        {
            if (tx_ipde1.Text != "" && tx_ipde2.Text != "" && tx_ipde3.Text != "" && tx_ipde4.Text != "" && tx_cidr.Text != "")
            {
                bt_calculer.Enabled = true;
            }
            else
            {
                bt_calculer.Enabled = false;
            }

            int cidr_total;
            if (tx_cidr.Text != "")
            {
                cidr_total = int.Parse(tx_cidr.Text);
                if (cidr_total >= 1 && cidr_total <= 32)
                {
                    bt_calculer.Enabled = true;
                    lb_cidrallert.Visible = false;
                }
                else
                {
                    bt_calculer.Enabled = false;
                    lb_cidrallert.Visible = true;
                }
            }
        }
    }
}
