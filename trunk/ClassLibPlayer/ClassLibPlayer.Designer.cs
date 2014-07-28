namespace ClassLibPlayer
{
    partial class ClassLibPlayer
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.grid = new CSharpUI.UI2048Grid();
            this.mBtnStart = new System.Windows.Forms.Button();
            this.mBtnReset = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // grid
            // 
            this.grid.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.grid.BackColor = System.Drawing.SystemColors.ControlDark;
            this.grid.Location = new System.Drawing.Point(13, 48);
            this.grid.Name = "grid";
            this.grid.Size = new System.Drawing.Size(280, 280);
            this.grid.TabIndex = 0;
            // 
            // mBtnStart
            // 
            this.mBtnStart.Location = new System.Drawing.Point(217, 13);
            this.mBtnStart.Name = "mBtnStart";
            this.mBtnStart.Size = new System.Drawing.Size(75, 23);
            this.mBtnStart.TabIndex = 1;
            this.mBtnStart.Text = "Start";
            this.mBtnStart.UseVisualStyleBackColor = true;
            this.mBtnStart.Click += new System.EventHandler(this.mBtnStart_Click);
            // 
            // mBtnReset
            // 
            this.mBtnReset.Location = new System.Drawing.Point(136, 13);
            this.mBtnReset.Name = "mBtnReset";
            this.mBtnReset.Size = new System.Drawing.Size(75, 23);
            this.mBtnReset.TabIndex = 2;
            this.mBtnReset.Text = "Reset";
            this.mBtnReset.UseVisualStyleBackColor = true;
            this.mBtnReset.Click += new System.EventHandler(this.mBtnReset_Click);
            // 
            // ClassLibPlayer
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(305, 341);
            this.Controls.Add(this.mBtnReset);
            this.Controls.Add(this.mBtnStart);
            this.Controls.Add(this.grid);
            this.Name = "ClassLibPlayer";
            this.Text = "ClassLib Player";
            this.ResumeLayout(false);

        }

        #endregion

        private CSharpUI.UI2048Grid grid;
        private System.Windows.Forms.Button mBtnStart;
        private System.Windows.Forms.Button mBtnReset;
    }
}

