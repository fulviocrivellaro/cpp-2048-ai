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
        private uint mSize;
        private Label[,] tiles;

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
                        this[c, r] = value[c, r];
                    });
            }
        }

        public int this[uint c, uint r]
        {
            set
            {
                var tile = tiles[c, r];
                tiles[c, r].Text = value > 0
                    ? tiles[c, r].Text = ((int)Math.Pow(2, value)).ToString()
                    : string.Empty;
                tiles[c, r].BackColor = mColors[value];
                tiles[c, r].ForeColor = value > 2 ? Color.White : Color.Black;
            }
        }

        public UI2048Grid()
        {
            InitializeComponent();
        }

        public void CodeInitialization(uint size)
        {
            mSize = size;
            tiles = new Label[mSize, mSize];
            
            this.SuspendLayout();

            RunOnTiles((c, r) =>
            {
                this.tiles[c, r] = new System.Windows.Forms.Label();
                var tile = tiles[c, r];

                tile.BackColor = System.Drawing.SystemColors.ActiveCaption;
                tile.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
                tile.Font = new System.Drawing.Font("Impact", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
                tile.Margin = new System.Windows.Forms.Padding(3);
                tile.Name = "tile00";
                tile.TabIndex = 1;
                tile.Text = "4192";
                tile.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
                
                this.Controls.Add(tile);
            });
            UI2048Grid_Resize(this, null);

            this.ResumeLayout(false);
        }

        internal void RunOnTiles(Action<uint, uint> action)
        {
            for (uint c = 0; c < mSize; ++c)
            {
                for (uint r = 0; r < mSize; ++r)
                {
                    action(c, r);
                }
            }
        }

        private const float TileToBorderRatio = 10.0f;
        private void UI2048Grid_Resize(object sender, EventArgs e)
        {
            var itemsCount = ((mSize * TileToBorderRatio) + mSize + 1);
            var wdtItem = (float)Size.Width / itemsCount;
            var hgtItem = (float)Size.Height / itemsCount;
            var tileWdt = TileToBorderRatio * wdtItem;
            var tileHgt = TileToBorderRatio * hgtItem;
            RunOnTiles((c, r) =>
            {
                var tile = tiles[c, r];

                tile.Location = new System.Drawing.Point(
                    (int)((1 + r) * wdtItem + r * tileWdt),
                    (int)((1 + c) * hgtItem + c * tileHgt));
                tile.Size = new System.Drawing.Size((int)tileWdt, (int)tileHgt);
            });
        }
    }
}
