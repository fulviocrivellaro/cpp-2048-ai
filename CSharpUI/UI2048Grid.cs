using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSharpUI
{
    public partial class UI2048Grid: UserControl
    {
        private int mSize = 4;
        private Label[,] tiles = new Label[4, 4];

        private readonly Color[] mColors = new[]
            {
                SystemColors.Control,   //     0
                Color.LightGray,        //     2
                Color.Tan,              //     4
                Color.SandyBrown,       //     8
                Color.Coral,            //    16
                Color.Salmon,           //    32
                Color.Crimson,          //    64
                Color.Khaki,            //   128
                Color.Gold,             //   256
                Color.Goldenrod,        //   512
                Color.Orange,           //  1024
                Color.DarkGoldenrod,    //  2048
                Color.LightGreen,       //  4096
                Color.LimeGreen,        //  8192 ?
                Color.Green,            // 16384 ?!?
            };

        public int[,] Grid
        {
            set
            {
                RunOnTiles((c, r) =>
                    {
                        if (value[c, r] == 0)
                        {
                            tiles[c, r].Text = string.Empty;
                        }
                        else
                        {
                            tiles[c, r].Text = ((int)Math.Pow(2, value[c, r])).ToString();
                        }

                        tiles[c, r].BackColor = mColors[value[c, r]];
                        tiles[c, r].ForeColor = value[c, r] > 2 ? Color.White : Color.Black;
                    });
            }
        }

        public UI2048Grid()
        {
            InitializeComponent();
        }

        public void CodeInitialization(int size)
        {
            mSize = size;
            
            this.SuspendLayout();

            RunOnTiles((r, c) =>
            {
                this.tiles[r, c] = new System.Windows.Forms.Label();
                var tile = tiles[r, c];

                tile.BackColor = System.Drawing.SystemColors.ActiveCaption;
                tile.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
                tile.Font = new System.Drawing.Font("Impact", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
                tile.Location = new System.Drawing.Point(3+c*70, 3+r*70);
                tile.Margin = new System.Windows.Forms.Padding(3);
                tile.Name = "tile00";
                tile.Size = new System.Drawing.Size(64, 64);
                tile.TabIndex = 1;
                tile.Text = "4192";
                tile.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
                
                this.Controls.Add(tile);
            });

            this.ResumeLayout(false);
        }

        internal void RunOnTiles(Action<int, int> action)
        {
            for (var r = 0; r < mSize; ++r)
            {
                for (var c = 0; c < mSize; ++c)
                {
                    action(r, c);
                }
            }
        }
    }
}
