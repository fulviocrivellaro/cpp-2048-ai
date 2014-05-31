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
        private const int SIZE = 4;

        private int mPoints = 0;

        private Dictionary<char, CppDirection> mDirectionMap = new Dictionary<char, CppDirection>();
        private Cpp2048ClassLib.Cpp2048 core = new Cpp2048ClassLib.Cpp2048();

        private int[,] valueGrid = new int[SIZE,SIZE];

        public ClassLibPlayer()
        {
            InitializeComponent();

            grid.KeyPress += GameUI_KeyPress;

            mDirectionMap.Add('i', CppDirection.up);
            mDirectionMap.Add('l', CppDirection.right);
            mDirectionMap.Add('k', CppDirection.down);
            mDirectionMap.Add('j', CppDirection.left);

            core.AddNewTile();
            RefreshUI();
        }

        private void RefreshUI()
        {
            for (var col = 0; col < SIZE; ++col)
            {
                for (var row = 0; row < SIZE; ++row)
                {
                    valueGrid[col, row] = core.GetValueForPosition(col, row);
                }
            }
            grid.Grid = valueGrid;

            Text = string.Format("2048 - Pts: {0}", mPoints);
        }

        private void GameUI_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (mDirectionMap.ContainsKey(e.KeyChar))
            {
                var direction = mDirectionMap[e.KeyChar];
                if (!core.CanMove(direction)) return;

                mPoints += core.Move(direction);
                core.AddNewTile();

                RefreshUI();
            }
        }
    }
}
