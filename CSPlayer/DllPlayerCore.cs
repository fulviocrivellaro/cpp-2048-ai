using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace DLLPlayer
{
    static class DllPlayerCore
    {
        private const int SIZE = 4;
        private const int BITS_PER_TILE = 4;
        private const string dllPath = @"D:\Progetti\cpp\2048\Debug\2048.Core.Dll.dll";

        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Stalled(long token);

        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool CanMoveUp(long token);
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool CanMoveLeft(long token);
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool CanMoveDown(long token);
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool CanMoveRight(long token);

        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern long MoveUp(long token);
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern long MoveLeft(long token);
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern long MoveDown(long token);
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern long MoveRight(long token);

        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern long AddNewTile(long token);

        internal enum Directions
        {
            Up,
            Down,
            Left,
            Right
        }

        internal static int[,] GetStatusFromToken(long token)
        {
            var grid = new int[4, 4];
	        for (int r = 0; r < SIZE; ++r)
	        {
		        for (int c = 0; c < SIZE; ++c)
		        {
			        grid[c, r] = GetValueForPosition(token, c, r);
		        }
	        }
            return grid;
        }

        private static int BITS_PWR = (int)Math.Pow(2, BITS_PER_TILE);
        private static int GetValueForPosition(long token, int column, int row)
        {
	        var idx = SIZE * row + column;
	        long mask = BITS_PWR - 1;

	        for (var i=0; i<idx; ++i)
	        {
		        mask = mask << BITS_PER_TILE;
	        }
	        mask &= token;
	        for (var i=0; i<idx; ++i)
	        {
		        mask = mask >> BITS_PER_TILE;
	        }
	
	        return (int)mask;
        }
    }
}
