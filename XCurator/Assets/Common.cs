using System.Collections;
using UnityEngine;

namespace Common
{
	public struct Block
	{
		public bool correct;       //正解
		public bool draw_frag;
		public int hint;
	}

	public static class Define
	{
		public const int NUM_MAT_MAX = 10;
	
	}
}