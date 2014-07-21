using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClassLibPlayer
{
    public partial class ClassLibPlayer : Form
    {
        private static readonly int SIZE = MilCore.CSMilGrid.getSize();

        private uint mPoints = 0;

        private Dictionary<char, CppDirection> mDirectionMap = new Dictionary<char, CppDirection>();
        private MilCore.CSMilGrid core = new MilCore.CSMilGrid();

        private int[,] valueGrid;

        private bool mAutoplayed = false;
        private static readonly bool mShouldAutoplay = false;

        public ClassLibPlayer()
        {
            valueGrid = new int[SIZE, SIZE];

            InitializeComponent();
            grid.CodeInitialization(SIZE);

            grid.KeyPress += GameUI_KeyPress;

            mDirectionMap.Add('i', CppDirection.up);
            mDirectionMap.Add('l', CppDirection.right);
            mDirectionMap.Add('k', CppDirection.down);
            mDirectionMap.Add('j', CppDirection.left);

            core.AddRandomTile();
            RefreshUI();

            //AutoPlay();
        }

        private void RefreshUI()
        {
            for (byte col = 0; col < SIZE; ++col)
            {
                for (byte row = 0; row < SIZE; ++row)
                {
                    valueGrid[col, row] = core.GetValue(col, row);
                }
            }
            grid.Grid = valueGrid;

            Text = string.Format("2048 - Pts: {0}", mPoints);
        }

        private void GameUI_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (mShouldAutoplay && !mAutoplayed)
            {
                mAutoplayed = true;
                //AutoPlay();
                return;
            }

            if (mDirectionMap.ContainsKey(e.KeyChar))
            {
                var direction = mDirectionMap[e.KeyChar];
                if (!core.CanMove(direction)) return;

                mPoints += core.Move(direction);
                core.AddRandomTile();

                RefreshUI();
            }
        }

        //private void AutoPlay()
        //{
        //    while (!core.IsStalled())
        //    {
        //        mPoints += core.AutoPlay();

        //        core.AddRandomTile();
        //        RefreshUI();
        //        Application.DoEvents();
        //    }
        //}
    }
}
