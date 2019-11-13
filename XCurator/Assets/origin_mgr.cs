using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Common;


public class origin_mgr : MonoBehaviour
{
	public Vector3Int stage_size = new Vector3Int(10, 10, 10);
	[SerializeField]
	private GameObject draw_obj;
	public Material[] num_mat = new Material[Define.NUM_MAT_MAX];
	public Block[,,] block;
	public int miss_count;	//残り不正解ブロック数
	int correct_count;		//残り正解ブロック数

	public bool game_over;	//ゲームオーバーフラグ
	public bool clear;		//クリアフラグ

	public Ray ray;			//レイキャスト判定

	bool key_down;
	// Start is called before the first frame update
	void Start()
    {
		block = new Block[stage_size.z, stage_size.y, stage_size.x];

		block[0, 0, 0].correct = true;
		block[1, 0, 0].correct = true;
		miss_count = 0;
		correct_count = 0;
		//ヒント判定
		for (int z = 0; z < stage_size.z; z++)
		{
			for (int y = 0; y < stage_size.y; y++)
			{
				for (int x = 0; x < stage_size.x; x++)
				{
					hint_counter(new Vector3Int(x, y, z));
					block[z,y,x].draw_frag = true;
				}

			}
		}


		//オブジェクト生成
		for (int z = 0; z < stage_size.z; z++)
		{
			for (int y = 0; y < stage_size.y; y++)
			{
				for (int x = 0; x < stage_size.x; x++)
				{

					if (block[z, y, x].draw_frag)
					{
						
						block[z,y,x].obj = Instantiate(draw_obj, new Vector3(0.0f, 0.0f, 0.0f), Quaternion.identity);
						block[z, y, x].obj.transform.localScale = transform.localScale;
						block[z, y, x].obj.transform.parent = transform;
						block[z, y, x].obj.transform.localPosition = new Vector3((1.0f * x) - (stage_size.x / 2), (1.0f * y) - (stage_size.y / 2), (1.0f * z) - (stage_size.z / 2));
						block_mgr mgr = block[z, y, x].obj.GetComponent<block_mgr>();
						mgr.block_mat = num_mat[block[z, y, x].hint];
						mgr.data = block[z, y, x];
						mgr.index = new Vector3Int(x, y, z);
						if (mgr.data.correct)
						{
							correct_count++;
						}
						else
						{
							miss_count++;
						}
					}
				}
			}
		}




    }

    // Update is called once per frame
    void Update()
    {

		/*//回転
		if (Input.GetKey(KeyCode.W))
		{

			transform.Rotate(new Vector3(5, 0, 0), Space.World);
		}
		if (Input.GetKey(KeyCode.S))
		{
			transform.Rotate(new Vector3(-5, 0, 0), Space.World);
		}
		if (Input.GetKey(KeyCode.D))
		{
			transform.Rotate(new Vector3(0, -5, 0), Space.World);
		}
		if (Input.GetKey(KeyCode.A))
		{
			transform.Rotate(new Vector3(0, 5, 0), Space.World);
		}

		//拡縮
		float scroll = Input.GetAxis("Mouse ScrollWheel");
		Vector3 pos_inst = camera.transform.position + new Vector3(0, 0, scroll * Define.ZOOM_SPEED);
		if (scroll > 0 && pos_inst.z > Define.ZOOM_MAX)
		{
			pos_inst.z = Define.ZOOM_MAX;
		}
		else if (scroll < 0 && pos_inst.z < Define.ZOOM_MIN)
		{
			pos_inst.z = Define.ZOOM_MIN;
		}
		camera.transform.position = pos_inst;


		Ray ray = camera.ScreenPointToRay(Input.mousePosition);*/

		RaycastHit hit;
		if (Physics.Raycast(ray, out hit))
		{
			GameObject obj = hit.collider.gameObject;
			obj.GetComponent<block_mgr>().hit_frag = true;
			if (Input.GetMouseButtonDown(0))
			{
				
				block_mgr mgr = obj.GetComponent<block_mgr>();
				if (!mgr.data.correct)
				{
					Vector3Int index_pos = hit.collider.gameObject.GetComponent<block_mgr>().index;
					block[index_pos.z, index_pos.y, index_pos.x].draw_frag = false;
					Destroy(hit.collider.gameObject);
					miss_count--;
				}
				else
				{
					game_over = true;
				}
				
			}
			//Debug.Log(hit.collider.gameObject.transform.position);
		}

		if(miss_count <= 0)
		{
			clear = true;
		}

		//Debug.Log(block[0,0,0].obj.transform.position);
	}


	void hint_counter(Vector3Int pos)
	{
		for (int z = -1; z < 2; z++)
		{
			for (int y = -1; y < 2; y++)
			{
				for (int x = -1; x < 2; x++)
				{
					Vector3Int search_pos = new Vector3Int(pos.x + x, pos.y + y, pos.z + z);
					//範囲外と自分判定
					if(search_pos.x < 0 || search_pos.x >= stage_size.x ||
						search_pos.y < 0 || search_pos.y >= stage_size.y ||
						search_pos.z < 0 || search_pos.z >= stage_size.z ||
						pos == search_pos
						)
					{
						continue;
					}
					
					if(block[search_pos.z, search_pos.y, search_pos.x].correct)
					{
						block[pos.z, pos.y, pos.x].hint++;
						//block[search_pos.z, search_pos.y, search_pos.x].hint++;
					}
				}
			}
		}
	}
}
