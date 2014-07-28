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
    public enum Status
    {
        Stopped, Playing, Stalled
    }

    public partial class ClassLibPlayer : Form, IGameHolder
    {
        private static readonly uint SIZE = MilCore.CSMilGrid.getSize();
        private IPlayer mPlayer;

        private Status mStatus = Status.Stopped;

        public ClassLibPlayer()
        {
            InitializeComponent();
            grid.CodeInitialization(SIZE);

            mPlayer = new HumanPlayer(grid, this, SIZE);

            RefreshUI();
        }

        private void RefreshUI()
        {
            switch (mStatus)
            {
                case Status.Stopped:
                    mBtnReset.Enabled = false;
                    mBtnStart.Enabled = true;
                    break;
                case Status.Stalled:
                    mBtnReset.Enabled = true;
                    mBtnStart.Enabled = true;                    
                    break;
                //case Status.Running:
                default:
                    mBtnReset.Enabled = true;
                    mBtnStart.Enabled = false;
                    break;
            }
        }

        private void mBtnStart_Click(object sender, EventArgs e)
        {
            mPlayer.Start();
            grid.Focus();
            mStatus = Status.Playing;
            RefreshUI();
        }

        private void mBtnReset_Click(object sender, EventArgs e)
        {
            mPlayer.Reset();
            mStatus = Status.Stopped;
            RefreshUI();
        }

        public void UpdatePoints(uint points)
        {
            switch (mStatus)
            {
                case Status.Stopped:
                    Text = "2048";
                    break;
                case Status.Stalled:
                    Text = string.Format("2048 - Game over: {0}", points);
                    break;
                //case Status.Running:
                default:
                    Text = string.Format("2048 - Pts: {0}", points);
                    break;
            }
        }

        public void Stalled()
        {
            mStatus = Status.Stalled;
            RefreshUI();
        }

        public int this[uint c, uint r]
        {
            set
            {
                grid[c, r] = value;
            }
        }
    }
}
