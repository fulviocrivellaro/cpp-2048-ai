using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibPlayer
{
    public interface IGameHolder
    {
        int this[uint c, uint r]
        {
            set;
        }

        // notifies a new data
        void UpdatePoints(uint points);

        // notifies the stall
        void Stalled();
    }
}
