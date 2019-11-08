using System.Collections;
using UnityEngine;

namespace Common
{
    public static class Define
    {
        public const int STAGE_MAX_Y = 20;      //ステージ縦幅
        public const int STAGE_MAX_X = 10;      //ステージ横幅
        public const int BLOCK_MAX_Y = 5;       //ブロック最大縦幅
        public const int BLOCK_MAX_X = 5;       //ブロック最大横幅
        public const int BLOCK_TYPE = 7;        //ブロックの種類最大数
        public const float MOVE_TIME_MAX = 1.0f;//有余
        public const float BLOCK_2D_SIZE = 0.40f;
        public const int RAND_NUM_MAX_SIZE = 30;

        public enum ACT
        {
            NO_ACT,
            RIGHT,
            LEFT,
            DOWN,
            RIGHT_ROLL,
            LEFT_ROLL,
            HOLD
        }

        public enum STEP
        {
            NO,
            SPWAN,
            MOVE
        }
    }
}