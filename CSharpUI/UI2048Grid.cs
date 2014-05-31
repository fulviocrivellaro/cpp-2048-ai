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
        private const int size = 4;
        private Label[,] tiles = new Label[size, size];

        private Color[] mColors;

        private Font darkFont;
        private Font liteFont;

        public int[,] Grid
        {
            set
            {
                for (var c = 0; c < size; ++c)
                {
                    for (var r = 0; r < size; ++r)
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
                    }
                }
            }
        }

        public UI2048Grid()
        {
            InitializeComponent();

            // store labels
            tiles[0, 0] = tile00;
            tiles[0, 1] = tile01;
            tiles[0, 2] = tile02;
            tiles[0, 3] = tile03;
            tiles[1, 0] = tile10;
            tiles[1, 1] = tile11;
            tiles[1, 2] = tile12;
            tiles[1, 3] = tile13;
            tiles[2, 0] = tile20;
            tiles[2, 1] = tile21;
            tiles[2, 2] = tile22;
            tiles[2, 3] = tile23;
            tiles[3, 0] = tile30;
            tiles[3, 1] = tile31;
            tiles[3, 2] = tile32;
            tiles[3, 3] = tile33;

            // and colors
            mColors = new[]
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
        }
    }
}
