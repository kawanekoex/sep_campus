using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Common;


public class origin_mgr : MonoBehaviour
{
	Vector3Int stage_size = new Vector3Int(5, 5, 5);
	[SerializeField]
	private GameObject draw_obj;
	public Material[] num_mat = new Material[Define.NUM_MAT_MAX];
	public Camera camera;
	Block[,,] block;
	public int miss_count;
	int correct_count;

	public bool game_over;
	public bool clear;

	bool key_down;
	// Start is called before the first frame update
	void Start()
    {
		block = new Block[stage_size.z, stage_size.y, stage_size.x];

		block[0, 0, 0].correct = true;
		block[0, 0, 1].correct = true;
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
						GameObject obj = Instantiate(draw_obj, new Vector3(0.0f, 0.0f, 0.0f), Quaternion.identity);
						obj.transform.localScale = transform.localScale;
						obj.transform.parent = transform;
						obj.transform.localPosition = new Vector3((1.0f * x) - (stage_size.x / 2),(1.0f * y) - (stage_size.y / 2), (1.0f * z) - (stage_size.z / 2));
						block_mgr mgr = obj.GetComponent<block_mgr>();
						mgr.block_mat = num_mat[block[z, y, x].hint];
						mgr.data = block[z, y, x];
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
		Vector3 rot = transform.eulerAngles;

		//回転
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


		Ray ray = camera.ScreenPointToRay(Input.mousePosition);
		RaycastHit hit;
		if (Physics.Raycast(ray, out hit))
		{
			if (Input.GetMouseButtonDown(0))
			{
				GameObject obj = hit.collider.gameObject;
				block_mgr mgr = obj.GetComponent<block_mgr>();
				if (!mgr.data.correct)
				{
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
