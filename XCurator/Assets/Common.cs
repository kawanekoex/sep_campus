using System.Collections;
using UnityEngine;

namespace Common
{
	public struct Block
	{
		public bool correct;       //正解
		public bool draw_frag;
		public int hint;
		public GameObject obj;
	}

	public static class Define
	{
		public const int NUM_MAT_MAX = 10;
		public const float ZOOM_MIN = -20.0f;
		public const float ZOOM_MAX = -5.0f;
		public const float ZOOM_SPEED = 4.0f;

	}
}