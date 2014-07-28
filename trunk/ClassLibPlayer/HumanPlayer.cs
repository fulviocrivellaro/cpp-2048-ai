using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClassLibPlayer
{
    class HumanPlayer : IPlayer
    {
        private readonly UserControl mForm;
        private readonly IGameHolder mGameHolder;
        private readonly uint mSize;

        private readonly Dictionary<char, CppDirection> mDirectionMap = new Dictionary<char, CppDirection>();
        private readonly MilCore.CSMilGrid core = new MilCore.CSMilGrid();
        private uint mPoints;

        public HumanPlayer(UserControl parent, IGameHolder gameHolder, uint size)
        {
            this.mForm = parent;
            this.mGameHolder = gameHolder;
            this.mSize = size;

            mDirectionMap.Add('i', CppDirection.up);
            mDirectionMap.Add('l', CppDirection.right);
            mDirectionMap.Add('k', CppDirection.down);
            mDirectionMap.Add('j', CppDirection.left);
        }

        public void Start()
        {
            mForm.KeyPress += GameUI_KeyPress;
            core.Reset();

            core.AddRandomTile();

            UpdateGameHolder();
        }

        public void Stop()
        {
            mForm.KeyPress -= GameUI_KeyPress;
        }

        public void Reset()
        {
            core.Reset();
        }

        private void GameUI_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (mDirectionMap.ContainsKey(e.KeyChar))
            {
                var direction = mDirectionMap[e.KeyChar];
                if (!core.CanMove(direction)) return;

                mPoints += core.Move(direction);
                core.AddRandomTile();

                UpdateGameHolder();
            }
        }

        private void UpdateGameHolder()
        {
            for (byte c = 0; c < mSize; ++c)
            {
                for (byte r = 0; r < mSize; ++r)
                {
                    mGameHolder[c, r] = core.GetValue(c, r);
                }
            }

            mGameHolder.UpdatePoints(mPoints);
        }
    }
}
