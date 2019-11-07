using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Common;
using System;

public class ai_input : MonoBehaviour
{
   
    public GameObject mgr;
    private List<Define.ACT> act = new List<Define.ACT>();

    block[,] m_stage = new block[Define.STAGE_MAX_Y + Define.BLOCK_MAX_Y, Define.STAGE_MAX_X];
    private List<Vector2Int> block_pos = new List<Vector2Int>();
    private int block_height;
    public Vector2Int m_pos;
    public Vector2Int m_move_pos;
    public int m_move_rotation_count;
    public int m_rotation_count;
    public int m_id;
    public int m_kaitenn_num;
    public bool[,] block_date = new bool[Define.BLOCK_MAX_Y, Define.BLOCK_MAX_X];
    public int[,] j_point = new int[Define.STAGE_MAX_X, 4];


    // Start is called before the first frame update
    void Start()
    {
        block_height = 0;
    }

    // Update is called once per frame
    void Update()
    {
        Tetris_mgr obj = mgr.GetComponent<Tetris_mgr>();
        Define.STEP s = obj.ai_step;

        if(s == Define.STEP.SPWAN)
        {
            initialize();
            pos_judge();
            mgr.GetComponent<Tetris_mgr>().ai_step = Define.STEP.MOVE;
        }
        else if(s == Define.STEP.MOVE)
        {
            move(obj.m_block.pos);
        }
    }

    private void initialize()
    {
        Tetris_mgr obj = mgr.GetComponent<Tetris_mgr>();
        m_id = obj.m_block.id;
        m_kaitenn_num = 0;
        m_rotation_count = 0;
        block_height = 0;
        Array.Copy(obj.n_block[m_id].block_date, block_date, obj.n_block[m_id].block_date.Length);
        Array.Copy(obj.block_stage, m_stage, obj.block_stage.Length);
        block_pos.Clear();

        for (int y = 0; y < Define.BLOCK_MAX_Y; y++)
        {
            for (int x = 0; x < Define.BLOCK_MAX_X; x++)
            {
                if (block_date[y, x])
                {
                    block_pos.Add(new Vector2Int(x - 2, y - 2));
                }
            }
        }
        //高さ測定

        for (int y = 0; y < Define.STAGE_MAX_Y + Define.BLOCK_MAX_Y; y++)
        {
            for (int x = 0; x < Define.STAGE_MAX_X; x++)
            {
                if (m_stage[y, x].draw_frag)
                {
                    block_height++;
                    break;
                }
            }
        }
    }

    private void pos_judge()
    {
        //j_point初期化
        {
            int[,] a = new int[Define.STAGE_MAX_X,4];
            Array.Copy(a, j_point, a.Length);
        }

        for (int x = 0; x < Define.STAGE_MAX_X; x++)
        {
            for (int index = 0; index < 4; index++, rotation_block())
            {
                block[,] stage_inst = new block[Define.STAGE_MAX_Y + Define.BLOCK_MAX_Y, Define.STAGE_MAX_X];
                Array.Copy(m_stage, stage_inst, m_stage.Length);
                m_pos = new Vector2Int(x, 2);
			    //画面外判定
			    for (int i = 0; i < block_pos.Count; i++) {
				if (m_pos.x + block_pos[i].x< 0 || m_pos.x + block_pos[i].x >= Define.STAGE_MAX_X) {
					j_point[x,index] += -999;
					break;
				}

			    }
			    if (j_point[x,index] != 0) {
				    continue;
			    }
                    Vector2Int inst = fall_block();
			    //判定用領域に書き込み
			    for (int i = 0; i < block_pos.Count; i++) {
				    stage_inst[inst.y + block_pos[i].y,inst.x + block_pos[i].x] .draw_frag= true;
			    }

			    //隙間判定
			    for (int i = 0; i < block_pos.Count; i++) {
				    if (inst.y + block_pos[i].y >= Define.STAGE_MAX_Y + Define.BLOCK_MAX_Y - 1) {
					    continue;
				    }
				    if (!stage_inst[inst.y + block_pos[i].y + 1,inst.x + block_pos[i].x].draw_frag) {
					    j_point[x,index] += -5;
					    break;
				    }
			    }
			

			    //高さ
			    int count = 0;
			    for (int y = 0; y < Define.STAGE_MAX_Y + Define.BLOCK_MAX_Y; y++) {
				    for (int x_a = 0; x_a < Define.STAGE_MAX_X; x_a++) {
					    if (stage_inst[y,x_a].draw_frag) {
						    count++;
						    break;
					    }
				    }
			    }
			    int height = block_height - count;
			    if (height< 0) {
				    j_point[x,index] += height;
			    }
			
			    //横1列判定
			    for (int y = 0; y < Define.STAGE_MAX_Y + Define.BLOCK_MAX_Y; y++) {
				    for (int x_a = 0; x_a < Define.STAGE_MAX_X; x_a++) {
                        if (!stage_inst[y, x_a].draw_frag)
                        {
                            x_a = Define.STAGE_MAX_X;
                            break;
                        }


					    if (x_a == Define.STAGE_MAX_X - 1) {
						    j_point[inst.x,index] += 5;
					    }
				    }
			    }

		    }
		
	    }
        //移動位置決定
        int point_inst = -999;
        for (int x = 0; x < Define.STAGE_MAX_X; x++)
        {
            for (int index = 0; index < 4; index++)
            {
                if (point_inst < j_point[x,index])
                {
                    point_inst = j_point[x,index];
                    m_move_pos.x = x;
                    m_move_rotation_count = index;
                }

            }
        }

    }


    private void rotation_block()
    {
        bool[,] inst = new bool[Define.BLOCK_MAX_Y, Define.BLOCK_MAX_X];
        Array.Copy(block_date, inst, block_date.Length);

        for (int y = 0; y < Define.BLOCK_MAX_Y; y++)
        {
            for (int x = 0; x < Define.BLOCK_MAX_X; x++)
            {
                block_date[y,x] = inst[(Define.BLOCK_MAX_Y - 1) - x,y];
            }
        }

        block_pos.Clear();

        for (int y = 0; y < Define.BLOCK_MAX_Y; y++)
        {
            for (int x = 0; x < Define.BLOCK_MAX_X; x++)
            {
                if (block_date[y,x])
                {
                    block_pos.Add(new Vector2Int(x - 2, y - 2));
                }
            }
        }
    }

    private void move(Vector2Int player_pos)
    {
        act.Clear();
        if (m_move_rotation_count > m_rotation_count)
        {
            m_rotation_count++;
            act.Add(Define.ACT.RIGHT_ROLL);
        }
        if (player_pos.x > m_move_pos.x)
        {
            act.Add(Define.ACT.LEFT);
        }
        else if (player_pos.x < m_move_pos.x)
        {
            act.Add(Define.ACT.RIGHT);
        }
        else
        {
            act.Add(Define.ACT.DOWN);
        }
        mgr.GetComponent<Tetris_mgr>().act = new List<Define.ACT>(act);
    }
    private Vector2Int fall_block()
    {
        Vector2Int pos_inst = m_pos;
        while (true)
        {
            for (int i = 0; i < block_pos.Count; i++)
            {
                Vector2Int a = block_pos[i] + pos_inst;
                //外枠判定
                if (a.y >= Define.STAGE_MAX_Y + Define.BLOCK_MAX_Y)
                {
                    pos_inst.y--;
                    return pos_inst;
                }
                //ブロック判定
                if (m_stage[a.y,a.x].draw_frag)
                {
                    pos_inst.y--;
                    return pos_inst;
                }
            }
            pos_inst.y++;
        }
    }
}
