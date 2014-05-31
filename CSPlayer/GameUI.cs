using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Directions = DLLPlayer.DllPlayerCore.Directions;

namespace DLLPlayer
{

    public partial class GameUI : Form
    {
        private long mToken;
        private Dictionary<char, Directions> mDirectionMap = new Dictionary<char, Directions>();

        public GameUI()
        {
            InitializeComponent();
            grid.KeyPress += GameUI_KeyPress;

            mDirectionMap.Add('i', Directions.Up);
            mDirectionMap.Add('l', Directions.Right);
            mDirectionMap.Add('k', Directions.Down);
            mDirectionMap.Add('j', Directions.Left);

            mToken = DllPlayerCore.AddNewTile(0);
            grid.Grid = DllPlayerCore.GetStatusFromToken(mToken);
        }

        private void GameUI_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (mDirectionMap.ContainsKey(e.KeyChar))
            {
                switch (mDirectionMap[e.KeyChar])
                {
                    case Directions.Down:
                        if (!DllPlayerCore.CanMoveDown(mToken)) return;
                        mToken = DllPlayerCore.MoveDown(mToken);
                        break;
                    case Directions.Up:
                        if (!DllPlayerCore.CanMoveUp(mToken)) return;
                        mToken = DllPlayerCore.MoveUp(mToken);
                        break;
                    case Directions.Left:
                        if (!DllPlayerCore.CanMoveLeft(mToken)) return;
                        mToken = DllPlayerCore.MoveLeft(mToken);
                        break;
                    case Directions.Right:
                        if (!DllPlayerCore.CanMoveRight(mToken)) return;
                        mToken = DllPlayerCore.MoveRight(mToken);
                        break;
                }

                mToken = DllPlayerCore.AddNewTile(mToken);
                grid.Grid = DllPlayerCore.GetStatusFromToken(mToken);
            }
        }
    }
}
