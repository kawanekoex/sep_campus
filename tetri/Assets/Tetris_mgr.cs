using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

using Common;

public struct Move_Block
{
    public Vector2Int v;
    public Vector2Int pos;
    public int id;
    public Color co;
    public float move_time;
    public float wait_time;
    public bool[,] block_date;
    public List<Vector2Int> block_pos;
}

public struct block {
  
    public Color co;
    public bool draw_frag;

}


public struct Next_block
{
    public Color co;
    public bool[,] block_date;
}

public class Tetris_mgr : MonoBehaviour
{
    //描画用
    private block[,,] block_draw;
    //判定用
    public block[,] block_stage;

    //動いてるブロック
    public Move_Block m_block;

    public bool gane_over;
    public int[] next = new int[5];
    public int hold;
    private int score;
    private int draw_score;

    //AI処理用
    public Define.STEP ai_step;

    public Next_block[] n_block = new Next_block[7];

    //アクションインターフェース
    public List<Define.ACT> act = new List<Define.ACT>();

    //private float frame;

    

    [SerializeField]
    private GameObject stage_obj;
    //[SerializeField]
    //private GameObject move_obj;
    [SerializeField]
    private GameObject score_object;
    //public float m_time;
    private float time;


    // Start is called before the first frame update
    void Start()
    {
        time = 0;
        m_block.pos = new Vector2Int(2,0);
        m_block.move_time = 0;
        m_block.wait_time = 0;
        m_block.block_pos = new List<Vector2Int>();

        hold = -1;

        block_draw = new block[2, Define.STAGE_MAX_Y, Define.STAGE_MAX_X];

        block_stage = new block[Define.STAGE_MAX_Y + Define.BLOCK_MAX_Y, Define.STAGE_MAX_X];
        m_block.block_date = new bool[Define.BLOCK_MAX_Y, Define.BLOCK_MAX_X];

        Load();
        for(int i = 0;i< 5; i++)
        {
            //乱数生成
            int rand = Random.Range(0, Define.BLOCK_TYPE);
            next[i] = rand;
        }
        //ブロック生成
        spawn_block();
        

    }

    // Update is called once per frame
    void Update()
    {
        time += Time.deltaTime;
        //m_block.move_time += Time.deltaTime;
        act_interface();
        wait_block();

        if (wall_judg_block())
        {
            m_block.wait_time += Time.deltaTime;
            if (m_block.wait_time >= 1.0f)
            {
                m_block.wait_time = 0.0f;
                for (int y = 0; y < Define.BLOCK_MAX_Y; y++)
                {
                    int index_y_num = (m_block.pos.y - 2) + y;
                    if (index_y_num >= 0 && index_y_num < Define.STAGE_MAX_Y + Define.BLOCK_MAX_Y)
                    {
                        for (int x = 0; x < Define.BLOCK_MAX_X; x++)
                        {
                            int index_x_num = (m_block.pos.x - 2) + x;
                            if (index_x_num >= 0 && index_x_num < Define.STAGE_MAX_X)
                            {
                                if (m_block.block_date[y,x])
                                {
                                    block_stage[index_y_num,index_x_num].draw_frag = true;
                                    block_stage[index_y_num, index_x_num].co = m_block.co;
                                }
                            }
                        }
                    }
                }

                for (int y = 0; y < Define.STAGE_MAX_Y + Define.BLOCK_MAX_Y; y++)
                {
                    for (int x = 0; x < Define.STAGE_MAX_X; x++)
                    {
                        if (!block_stage[y,x].draw_frag) break;


                        if (x == Define.STAGE_MAX_X - 1)
                        {
                            score += 1000;
                            tumeru(y);
                        }
                    }
                }

                for (int y = 0; y < Define.BLOCK_MAX_Y; y++)
                {
                    for (int x = 0; x < Define.STAGE_MAX_X; x++)
                    {
                        if (block_stage[y,x].draw_frag) gane_over = true;

                    }
                }



                spawn_block();
            }
        }
        else
        {
            m_block.pos += m_block.v;
        }

        

        m_block.v = new Vector2Int();

        //描画用に変換
        for (int y = 0; y < Define.STAGE_MAX_Y; y++)
        {
            for (int x = 0; x < Define.STAGE_MAX_X; x++)
            {
                block_draw[0,y, x] = block_stage[y + 5, x];
            }
        }
        for (int y = 0; y < 5; y++)
        {
            int index_y_num = (m_block.pos.y - 2) + y - 5;
            if (index_y_num >= 0 && index_y_num < 20)
            {
                for (int x = 0; x < 5; x++)
                {
                    int index_x_num = (m_block.pos.x - 2) + x;
                    if (index_x_num >= 0 && index_x_num < Define.STAGE_MAX_X)
                    {
                        if (m_block.block_date[y,x])
                        {
                            block_draw[0,index_y_num,index_x_num].draw_frag = true;
                            block_draw[0, index_y_num, index_x_num].co = m_block.co;
                        }
                    }
                }
            }
        }

        score_object.GetComponent<score_text_mgr>().score = score;
        for (int y = 0; y < Define.STAGE_MAX_Y; y++)
        {
            for (int x = 0; x < Define.STAGE_MAX_X; x++)
            {
                stage_obj.GetComponent<stage_mgr>().block_draw[y,x] = block_draw[0,y,x];
            }
           
        }
    }
    public void wait_block()
    {
        m_block.move_time += Time.deltaTime;
        if (m_block.move_time >= Define.MOVE_TIME_MAX)
        {
            m_block.move_time = 0.0f;
            m_block.v.y = 1;
        }
    }
    public void spawn_block()
    {
        m_block.block_pos.Clear();

        //ブロック生成
        for (int y = 0; y < Define.BLOCK_MAX_Y; y++)
        {
            for (int x = 0; x < Define.BLOCK_MAX_X; x++)
            {
                m_block.block_date[y, x] = n_block[next[0]].block_date[y, x];
                if (m_block.block_date[y,x])
                {
                    m_block.block_pos.Add(new Vector2Int(x - 2,y - 2));
                }
            }
        }

        m_block.co = n_block[next[0]].co;
        m_block.id = next[0];


        ai_step = Define.STEP.SPWAN;
        //初期位置設定
        m_block.pos.y = 2;
        m_block.pos.x = Define.STAGE_MAX_X / 2;

        //乱数生成
        int rand = Random.Range(0, Define.BLOCK_TYPE);
        for(int i = 1; i < 5; i++)
        {
            next[i - 1] = next[i];
        }

        next[4] = rand;
    }

    public void block_hold()
    {
        m_block.block_pos.Clear();

        //ブロック生成
        for (int y = 0; y < Define.BLOCK_MAX_Y; y++)
        {
            for (int x = 0; x < Define.BLOCK_MAX_X; x++)
            {

              

                m_block.block_date[y, x] = n_block[hold].block_date[y, x];


                if (m_block.block_date[y, x])
                {
                    m_block.block_pos.Add(new Vector2Int(x - 2, y - 2));
                }
            }

        }

        int num = m_block.id;

        m_block.co = n_block[hold].co;
        m_block.id = hold;
        hold = num;

        //当たり判定
        for (int i = 0; i < (int)m_block.block_pos.Count; i++)
        {
            Vector2Int a = m_block.block_pos[i] + m_block.pos;

            if (a.x < 0)
            {
                m_block.pos.x++;
                i = 0;
                continue;
            }
            else if (a.x >= Define.STAGE_MAX_X)
            {
                m_block.pos.x--;
                i = 0;
                continue;
            }

            if (block_stage[a.y, a.x].draw_frag)
            {
                m_block.pos.y--;
                i = 0;
                continue;
            }
        }
    }
    public void act_interface()
    {
        for (int i = 0; i < act.Count; i++)
        {
            if (act[i] == Define.ACT.DOWN)
            {
                m_block.move_time += Time.deltaTime * 20.0f;
                m_block.wait_time = 1.0f;
            }
            else if (act[i] == Define.ACT.LEFT)
            {
                m_block.v.x--;
                m_block.wait_time = 0;
            }
            else if (act[i] == Define.ACT.RIGHT)
            {
                m_block.v.x++;
                m_block.wait_time = 0;
            }

            else if (act[i] == Define.ACT.LEFT_ROLL)
            {
                kaitenn(false);
            }
            else if (act[i] == Define.ACT.RIGHT_ROLL)
            {
                kaitenn(true);
            }
            else if (act[i] == Define.ACT.HOLD)
            {
                if (hold != -1)
                {
                    block_hold();
                }
                else
                {
                    hold = m_block.id;
                    Vector2Int inst = m_block.pos;
                    spawn_block();
                    m_block.pos = inst;
                }
            }
        }
    }

   public bool wall_judg_block()
    {
        for (int i = 0; i < (int)m_block.block_pos.Count; i++)
        {
            Vector2Int a = m_block.block_pos[i] + m_block.pos;
            {
                //外枠判定
                Vector2Int a2 = a + m_block.v;
                if (a2.x < 0)
                {
                    m_block.v.x = 0;
                }
                if (a2.x >= Define.STAGE_MAX_X)
                {
                    m_block.v.x = 0;
                }

                if (a2.y >= Define.STAGE_MAX_Y + Define.BLOCK_MAX_Y)
                {
                    m_block.v.y = 0;
                    return true;
                }

            }
            //ブロック判定
            if (block_stage[a.y,a.x + m_block.v.x].draw_frag)
            {
                m_block.v.x = 0;
            }
            if (block_stage[a.y + m_block.v.y, a.x].draw_frag)
            {
                m_block.v.y = 0;
                return true;
            }

        }
        return false;
    }
    void kaitenn(bool right_f)
    {
        bool[,] inst = new bool[5,5];

        System.Array.Copy(m_block.block_date, inst, m_block.block_date.Length);

        for (int y = 0; y < Define.BLOCK_MAX_Y; y++)
        {
            for (int x = 0; x < Define.BLOCK_MAX_X; x++)
            {

                if (right_f)
                {
                    m_block.block_date[y,x] = inst[(Define.BLOCK_MAX_Y - 1) - x,y];
                }
                else
                {
                    m_block.block_date[y,x] = inst[x,(Define.BLOCK_MAX_X - 1) - y];
                }
            }
        }

        m_block.block_pos.Clear();

        for (int y = 0; y < Define.BLOCK_MAX_Y; y++)
        {
            for (int x = 0; x < Define.BLOCK_MAX_X; x++)
            {
                if (m_block.block_date[y,x])
                {
                    m_block.block_pos.Add(new Vector2Int(x - 2, y - 2));
                }
            }
        }
        //当たり判定
        for (int i = 0; i < (int)m_block.block_pos.Count;)
        {
            Vector2Int a = m_block.block_pos[i] + m_block.pos;

            if (a.x < 0)
            {
                m_block.pos.x++;
                i = 0;
                continue;
            }
            else if (a.x >= Define.STAGE_MAX_X)
            {
                m_block.pos.x--;
                i = 0;
                continue;
            }
            else if (a.y < 0)
            {
                m_block.pos.y--;
                i = 0;
                continue;
            }

            if (block_stage[a.y,a.x].draw_frag)
            {
                for(int j = 0; j < (int)m_block.block_pos.Count;j++)
                {
                    Vector2Int b = m_block.block_pos[i] + m_block.pos;

                    if (right_f)
                    {
                        b += new Vector2Int(1, -1);
                    }
                    else
                    {
                        b += new Vector2Int(-1, -1);
                    }

                    if (block_stage[b.y, b.x].draw_frag)
                    {
                        m_block.pos.y--;
                        i = 0;
                        break;
                    }
                    else if(j >= (int)m_block.block_pos.Count - 1)
                    {
                        if (right_f)
                        {
                            m_block.pos += new Vector2Int(1, -1);
                        }
                        else
                        {
                            m_block.pos += new Vector2Int(-1, -1);
                        }
                        i = 0;
                    }
                }
               
                continue;
            }
            i++;
        }
    }

    void tumeru(int d_y)
    {
        for (int y = d_y; y > Define.BLOCK_MAX_Y; y--)
        {
            for (int x = 0; x < Define.STAGE_MAX_X; x++)
            {
                block_stage[y,x] = block_stage[y - 1,x];
            }
        }

        //削除
        for (int i = 0; i < Define.STAGE_MAX_X; i++)
        {
            block_stage[Define.BLOCK_MAX_Y,i].draw_frag = false;
        }

    }

    void Load()
    {
        n_block[0].block_date = new bool[5, 5]
        {
            {false,false,false,false,false},
            { false,true,true,false,false},
            { false,true,true,false,false},
            { false,false,false,false,false},
            { false,false,false,false,false}
        };
        n_block[0].co = new Color(1.0f,1.0f, 0.0f, 1.0f);

        n_block[1].block_date = new bool[5, 5]
      {
           {false,false,false,false,false},
            {false,false,true,false,false},
            {false,false,true,false,false},
            {false,false,true,false,false},
            {false,false,true,false,false}
      };
        n_block[1].co = new Color(0.0f, 1.0f, 1.0f, 1.0f);

        n_block[2].block_date = new bool[5, 5]
      {
            {false,false,false,false,false},
            {false,false,true,false,false},
            {false,true,true,true,false},
            {false,false,false,false,false},
            {false,false,false,false,false}
      };
        n_block[2].co = new Color(1.0f, 0.0f, 1.0f, 1.0f);

        n_block[3].block_date = new bool[5, 5]
      {
            {false,false,false,false,false},
            {false,false,false,false,false},
            {false,true,true,false,false},
            {false,false,true,true,false},
            {false,false,false,false,false}
      };
        n_block[3].co = new Color(0.0f, 1.0f, 0.0f, 1.0f);

        n_block[4].block_date = new bool[5, 5]
      {
            {false,false,false,false,false},
            {false,false,false,false,false},
            {false,false,true,true,false},
            {false,true,true,false,false},
            {false,false,false,false,false}
      };
        n_block[4].co = new Color(1.0f, 0.0f, 0.0f, 1.0f);

        n_block[5].block_date = new bool[5, 5]
      {
            {false,false,false,false,false},
            {false,true,false,false,false},
            {false,true,true,true,false},
            {false,false,false,false,false},
            {false,false,false,false,false}
      };
        n_block[5].co = new Color(1.0f, 0.5f, 0.0f, 1.0f);

        n_block[6].block_date = new bool[5, 5]
      {
            {false,false,false,false,false},
            {false,false,false,true,false},
            {false,true,true,true,false},
            {false,false,false,false,false},
            {false,false,false,false,false}
      };
        n_block[6].co = new Color(0.0f, 0.0f, 1.0f, 1.0f);
    }
}


