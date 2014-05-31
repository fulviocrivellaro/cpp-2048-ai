namespace DLLPlayer
{
    partial class GameUI
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
            this.SuspendLayout();
            // 
            // grid
            // 
            this.grid.Location = new System.Drawing.Point(13, 13);
            this.grid.Name = "grid";
            this.grid.Size = new System.Drawing.Size(280, 280);
            this.grid.TabIndex = 0;
            // 
            // GameUI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(307, 307);
            this.Controls.Add(this.grid);
            this.Name = "GameUI";
            this.Text = "GameUI";
            this.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.GameUI_KeyPress);
            this.ResumeLayout(false);

        }

        #endregion

        private CSharpUI.UI2048Grid grid;
    }
}