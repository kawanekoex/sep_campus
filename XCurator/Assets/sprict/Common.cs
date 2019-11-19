﻿using System;
using System.Collections;
using UnityEngine;

namespace Common
{
	[Serializable]
	public struct Block
	{
		public bool correct;       //正解
		public bool draw_frag;
		public int hint;
		public GameObject obj;
		//public Block()
		//{
		//	correct = false;
		//	draw_frag = false;
		//	hint = 0;
		//	obj = null;
		//}
	}
	public class save_date
	{
		public int a;
		public int c;
	}
	public static class Define
	{
		public const int NUM_MAT_MAX = 27;
		public const float ZOOM_MIN = 5.0f;
		public const float ZOOM_MAX = 20.0f;
		public const float ZOOM_SPEED = 4.0f;
		public const int VERSION = 1;

		public enum DIRECTION_NUM
		{
			UP,
			DOWN,
			RIGHT,
			LEFT
		}


		

	}
}