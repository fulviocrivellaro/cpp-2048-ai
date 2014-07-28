using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibPlayer
{
    interface IPlayer
    {
        // asks to start
        void Start();

        // asks to stop
        void Stop();

        // reset
        void Reset();
    }
}
