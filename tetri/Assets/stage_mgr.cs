using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Common;

public class stage_mgr : MonoBehaviour
{
    public block[,] block_draw;
    public block[,] block_draw_check;
    [SerializeField]
    private GameObject draw_obj;
    // Start is called before the first frame update
    void Start()
    {
        block_draw = new block[Define.STAGE_MAX_Y, Define.STAGE_MAX_X];
        block_draw_check = new block[Define.STAGE_MAX_Y, Define.STAGE_MAX_X];
    }

    // Update is called once per frame
    void Update()
    {
        for (int y = 0; y < Define.STAGE_MAX_Y; y++)
        {
            for (int x = 0; x < Define.STAGE_MAX_X; x++)
            {
                //生成
                if (block_draw[y, x].draw_frag && !block_draw_check[y, x].draw_frag)
                {
                    block_draw_check[y, x].draw_frag = true;
                    block_draw_check[y, x].co = block_draw[y, x].co;
                    GameObject obj = Instantiate(draw_obj, new Vector3(0.0f,0.0f,0.0f), Quaternion.identity);
                    obj.GetComponent<obj_mgr>().index = new Vector2Int(x, y);
                    obj.GetComponent<obj_mgr>().c = block_draw_check[y, x].co;
                    obj.transform.localScale = transform.localScale;
                    obj.transform.parent = transform;
                    obj.transform.localPosition = new Vector3(1.0f * x, -1.0f * y, 0.0f);
                }
                //削除
                if (!block_draw[y, x].draw_frag && block_draw_check[y, x].draw_frag)
                {
                   
                    block_draw_check[y, x].draw_frag = false;
                    foreach (Transform child in transform)
                    {
                        if (child.tag != "Block") continue;
                        Vector2Int inst = new Vector2Int(x, y);
                        if (child.GetComponent<obj_mgr>().index == inst)
                        {
                            Destroy(child.gameObject);
                        }
                    }
                }
                //色変更
                if (block_draw[y, x].co != block_draw_check[y, x].co)
                {
                    block_draw_check[y, x].co = block_draw[y, x].co;
                    foreach (Transform child in transform)
                    {
                        if (child.tag != "Block") continue;
                        Vector2Int inst = new Vector2Int(x, y);
                        if (child.GetComponent<obj_mgr>().index == inst)
                        {
                            child.GetComponent<obj_mgr>().c = block_draw_check[y, x].co;
                        }
                    }
                }
            }
        }
    }
}
