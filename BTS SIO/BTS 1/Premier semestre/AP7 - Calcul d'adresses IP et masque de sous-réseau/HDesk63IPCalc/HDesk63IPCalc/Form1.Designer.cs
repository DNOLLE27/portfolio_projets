
namespace HDesk63IPCalc
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.tx_ipde1 = new System.Windows.Forms.TextBox();
            this.tx_cidr = new System.Windows.Forms.TextBox();
            this.bt_calculer = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.tx_ipbi1 = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.tx_masquede1 = new System.Windows.Forms.TextBox();
            this.tx_masquebi1 = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.tx_ipreseau = new System.Windows.Forms.TextBox();
            this.tx_nbhotes = new System.Windows.Forms.TextBox();
            this.tx_ipde2 = new System.Windows.Forms.TextBox();
            this.tx_ipde4 = new System.Windows.Forms.TextBox();
            this.tx_ipde3 = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.tx_ipbi2 = new System.Windows.Forms.TextBox();
            this.tx_ipbi3 = new System.Windows.Forms.TextBox();
            this.tx_ipbi4 = new System.Windows.Forms.TextBox();
            this.tx_masquebi2 = new System.Windows.Forms.TextBox();
            this.tx_masquebi3 = new System.Windows.Forms.TextBox();
            this.tx_masquebi4 = new System.Windows.Forms.TextBox();
            this.label13 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.label15 = new System.Windows.Forms.Label();
            this.tx_masquede3 = new System.Windows.Forms.TextBox();
            this.tx_masquede4 = new System.Windows.Forms.TextBox();
            this.tx_masquede2 = new System.Windows.Forms.TextBox();
            this.lb_cidrallert = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(84, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "Adresse IP :";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(47, 42);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 20);
            this.label2.TabIndex = 1;
            this.label2.Text = "CIDR :";
            // 
            // tx_ipde1
            // 
            this.tx_ipde1.Location = new System.Drawing.Point(102, 6);
            this.tx_ipde1.Name = "tx_ipde1";
            this.tx_ipde1.Size = new System.Drawing.Size(42, 27);
            this.tx_ipde1.TabIndex = 2;
            this.tx_ipde1.TextChanged += new System.EventHandler(this.tx_ipde1_TextChanged);
            // 
            // tx_cidr
            // 
            this.tx_cidr.Location = new System.Drawing.Point(102, 39);
            this.tx_cidr.Name = "tx_cidr";
            this.tx_cidr.Size = new System.Drawing.Size(62, 27);
            this.tx_cidr.TabIndex = 3;
            this.tx_cidr.TextChanged += new System.EventHandler(this.tx_cidr_TextChanged);
            // 
            // bt_calculer
            // 
            this.bt_calculer.Enabled = false;
            this.bt_calculer.Location = new System.Drawing.Point(142, 84);
            this.bt_calculer.Name = "bt_calculer";
            this.bt_calculer.Size = new System.Drawing.Size(94, 29);
            this.bt_calculer.TabIndex = 4;
            this.bt_calculer.Text = "Calculer";
            this.bt_calculer.UseVisualStyleBackColor = true;
            this.bt_calculer.Click += new System.EventHandler(this.bt_calculer_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 126);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(144, 20);
            this.label3.TabIndex = 5;
            this.label3.Text = "Adresse IP (Binaire) :";
            // 
            // tx_ipbi1
            // 
            this.tx_ipbi1.Enabled = false;
            this.tx_ipbi1.Location = new System.Drawing.Point(12, 149);
            this.tx_ipbi1.Name = "tx_ipbi1";
            this.tx_ipbi1.Size = new System.Drawing.Size(71, 27);
            this.tx_ipbi1.TabIndex = 6;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Cursor = System.Windows.Forms.Cursors.Default;
            this.label4.Location = new System.Drawing.Point(12, 179);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(171, 20);
            this.label4.TabIndex = 7;
            this.label4.Text = "Masque de sous-réseau :";
            // 
            // tx_masquede1
            // 
            this.tx_masquede1.Enabled = false;
            this.tx_masquede1.Location = new System.Drawing.Point(12, 228);
            this.tx_masquede1.Name = "tx_masquede1";
            this.tx_masquede1.Size = new System.Drawing.Size(43, 27);
            this.tx_masquede1.TabIndex = 8;
            // 
            // tx_masquebi1
            // 
            this.tx_masquebi1.Enabled = false;
            this.tx_masquebi1.Location = new System.Drawing.Point(12, 283);
            this.tx_masquebi1.Name = "tx_masquebi1";
            this.tx_masquebi1.Size = new System.Drawing.Size(84, 27);
            this.tx_masquebi1.TabIndex = 9;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Cursor = System.Windows.Forms.Cursors.Default;
            this.label5.Location = new System.Drawing.Point(12, 205);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(71, 20);
            this.label5.TabIndex = 10;
            this.label5.Text = "Décimal :";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Cursor = System.Windows.Forms.Cursors.Default;
            this.label6.Location = new System.Drawing.Point(12, 260);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(62, 20);
            this.label6.TabIndex = 11;
            this.label6.Text = "Binaire :";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Cursor = System.Windows.Forms.Cursors.Default;
            this.label7.Location = new System.Drawing.Point(12, 286);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(0, 20);
            this.label7.TabIndex = 12;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Cursor = System.Windows.Forms.Cursors.Default;
            this.label8.Location = new System.Drawing.Point(12, 330);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(152, 20);
            this.label8.TabIndex = 13;
            this.label8.Text = "Adresse IP du réseau :";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Cursor = System.Windows.Forms.Cursors.Default;
            this.label9.Location = new System.Drawing.Point(12, 383);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(123, 20);
            this.label9.TabIndex = 14;
            this.label9.Text = "Nombre d\'hôtes :";
            // 
            // tx_ipreseau
            // 
            this.tx_ipreseau.Location = new System.Drawing.Point(12, 353);
            this.tx_ipreseau.Name = "tx_ipreseau";
            this.tx_ipreseau.Size = new System.Drawing.Size(344, 27);
            this.tx_ipreseau.TabIndex = 15;
            // 
            // tx_nbhotes
            // 
            this.tx_nbhotes.Location = new System.Drawing.Point(12, 406);
            this.tx_nbhotes.Name = "tx_nbhotes";
            this.tx_nbhotes.Size = new System.Drawing.Size(344, 27);
            this.tx_nbhotes.TabIndex = 16;
            // 
            // tx_ipde2
            // 
            this.tx_ipde2.Location = new System.Drawing.Point(168, 6);
            this.tx_ipde2.Name = "tx_ipde2";
            this.tx_ipde2.Size = new System.Drawing.Size(42, 27);
            this.tx_ipde2.TabIndex = 17;
            this.tx_ipde2.TextChanged += new System.EventHandler(this.tx_ipde2_TextChanged);
            // 
            // tx_ipde4
            // 
            this.tx_ipde4.Location = new System.Drawing.Point(299, 6);
            this.tx_ipde4.Name = "tx_ipde4";
            this.tx_ipde4.Size = new System.Drawing.Size(42, 27);
            this.tx_ipde4.TabIndex = 18;
            this.tx_ipde4.TextChanged += new System.EventHandler(this.tx_ipde4_TextChanged);
            // 
            // tx_ipde3
            // 
            this.tx_ipde3.Location = new System.Drawing.Point(233, 6);
            this.tx_ipde3.Name = "tx_ipde3";
            this.tx_ipde3.Size = new System.Drawing.Size(42, 27);
            this.tx_ipde3.TabIndex = 19;
            this.tx_ipde3.TextChanged += new System.EventHandler(this.tx_ipde3_TextChanged);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(150, 13);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(12, 20);
            this.label10.TabIndex = 20;
            this.label10.Text = ".";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(216, 13);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(12, 20);
            this.label11.TabIndex = 21;
            this.label11.Text = ".";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(281, 13);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(12, 20);
            this.label12.TabIndex = 22;
            this.label12.Text = ".";
            // 
            // tx_ipbi2
            // 
            this.tx_ipbi2.Enabled = false;
            this.tx_ipbi2.Location = new System.Drawing.Point(89, 149);
            this.tx_ipbi2.Name = "tx_ipbi2";
            this.tx_ipbi2.Size = new System.Drawing.Size(71, 27);
            this.tx_ipbi2.TabIndex = 23;
            // 
            // tx_ipbi3
            // 
            this.tx_ipbi3.Enabled = false;
            this.tx_ipbi3.Location = new System.Drawing.Point(166, 149);
            this.tx_ipbi3.Name = "tx_ipbi3";
            this.tx_ipbi3.Size = new System.Drawing.Size(71, 27);
            this.tx_ipbi3.TabIndex = 24;
            // 
            // tx_ipbi4
            // 
            this.tx_ipbi4.Enabled = false;
            this.tx_ipbi4.Location = new System.Drawing.Point(243, 149);
            this.tx_ipbi4.Name = "tx_ipbi4";
            this.tx_ipbi4.Size = new System.Drawing.Size(71, 27);
            this.tx_ipbi4.TabIndex = 25;
            // 
            // tx_masquebi2
            // 
            this.tx_masquebi2.Enabled = false;
            this.tx_masquebi2.Location = new System.Drawing.Point(102, 283);
            this.tx_masquebi2.Name = "tx_masquebi2";
            this.tx_masquebi2.Size = new System.Drawing.Size(84, 27);
            this.tx_masquebi2.TabIndex = 26;
            // 
            // tx_masquebi3
            // 
            this.tx_masquebi3.Enabled = false;
            this.tx_masquebi3.Location = new System.Drawing.Point(192, 283);
            this.tx_masquebi3.Name = "tx_masquebi3";
            this.tx_masquebi3.Size = new System.Drawing.Size(84, 27);
            this.tx_masquebi3.TabIndex = 27;
            // 
            // tx_masquebi4
            // 
            this.tx_masquebi4.Enabled = false;
            this.tx_masquebi4.Location = new System.Drawing.Point(282, 283);
            this.tx_masquebi4.Name = "tx_masquebi4";
            this.tx_masquebi4.Size = new System.Drawing.Size(84, 27);
            this.tx_masquebi4.TabIndex = 28;
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(191, 235);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(12, 20);
            this.label13.TabIndex = 34;
            this.label13.Text = ".";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(126, 235);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(12, 20);
            this.label14.TabIndex = 33;
            this.label14.Text = ".";
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(60, 235);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(12, 20);
            this.label15.TabIndex = 32;
            this.label15.Text = ".";
            // 
            // tx_masquede3
            // 
            this.tx_masquede3.Enabled = false;
            this.tx_masquede3.Location = new System.Drawing.Point(143, 228);
            this.tx_masquede3.Name = "tx_masquede3";
            this.tx_masquede3.Size = new System.Drawing.Size(42, 27);
            this.tx_masquede3.TabIndex = 31;
            // 
            // tx_masquede4
            // 
            this.tx_masquede4.Enabled = false;
            this.tx_masquede4.Location = new System.Drawing.Point(209, 228);
            this.tx_masquede4.Name = "tx_masquede4";
            this.tx_masquede4.Size = new System.Drawing.Size(42, 27);
            this.tx_masquede4.TabIndex = 30;
            // 
            // tx_masquede2
            // 
            this.tx_masquede2.Enabled = false;
            this.tx_masquede2.Location = new System.Drawing.Point(78, 228);
            this.tx_masquede2.Name = "tx_masquede2";
            this.tx_masquede2.Size = new System.Drawing.Size(42, 27);
            this.tx_masquede2.TabIndex = 29;
            // 
            // lb_cidrallert
            // 
            this.lb_cidrallert.AutoSize = true;
            this.lb_cidrallert.ForeColor = System.Drawing.Color.Red;
            this.lb_cidrallert.Location = new System.Drawing.Point(170, 42);
            this.lb_cidrallert.Name = "lb_cidrallert";
            this.lb_cidrallert.Size = new System.Drawing.Size(338, 20);
            this.lb_cidrallert.TabIndex = 35;
            this.lb_cidrallert.Text = "Attention ! Veuillez saisir une valeur entre 1 et 32 !";
            this.lb_cidrallert.Visible = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(514, 447);
            this.Controls.Add(this.lb_cidrallert);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.label15);
            this.Controls.Add(this.tx_masquede3);
            this.Controls.Add(this.tx_masquede4);
            this.Controls.Add(this.tx_masquede2);
            this.Controls.Add(this.tx_masquebi4);
            this.Controls.Add(this.tx_masquebi3);
            this.Controls.Add(this.tx_masquebi2);
            this.Controls.Add(this.tx_ipbi4);
            this.Controls.Add(this.tx_ipbi3);
            this.Controls.Add(this.tx_ipbi2);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.tx_ipde3);
            this.Controls.Add(this.tx_ipde4);
            this.Controls.Add(this.tx_ipde2);
            this.Controls.Add(this.tx_nbhotes);
            this.Controls.Add(this.tx_ipreseau);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.tx_masquebi1);
            this.Controls.Add(this.tx_masquede1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.tx_ipbi1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.bt_calculer);
            this.Controls.Add(this.tx_cidr);
            this.Controls.Add(this.tx_ipde1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "HDesk63IPCalc";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox tx_ipde1;
        private System.Windows.Forms.TextBox tx_cidr;
        private System.Windows.Forms.Button bt_calculer;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox tx_ipbi1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox tx_masquede1;
        private System.Windows.Forms.TextBox tx_masquebi1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox tx_ipreseau;
        private System.Windows.Forms.TextBox tx_nbhotes;
        private System.Windows.Forms.TextBox tx_ipde2;
        private System.Windows.Forms.TextBox tx_ipde4;
        private System.Windows.Forms.TextBox tx_ipde3;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.TextBox tx_ipbi2;
        private System.Windows.Forms.TextBox tx_ipbi3;
        private System.Windows.Forms.TextBox tx_ipbi4;
        private System.Windows.Forms.TextBox tx_masquebi2;
        private System.Windows.Forms.TextBox tx_masquebi3;
        private System.Windows.Forms.TextBox tx_masquebi4;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.TextBox tx_masquede3;
        private System.Windows.Forms.TextBox tx_masquede4;
        private System.Windows.Forms.TextBox tx_masquede2;
        private System.Windows.Forms.Label lb_cidrallert;
    }
}

