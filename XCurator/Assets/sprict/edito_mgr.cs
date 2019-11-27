using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Common;
using System.IO;

public class block_log
{
	public bool del_frag;
	public Vector3Int index_pos;

	public block_log(bool a,Vector3Int b)
	{
		del_frag = a;
		index_pos = b;
	}
}



public class edito_mgr : MonoBehaviour
{
	public Ray ray;         //レイキャスト判定
	public static Vector3Int stage_size = new Vector3Int(5,5,5);
	public Camera m_camera;
	public Material mat;
	[SerializeField]
	private GameObject draw_obj;
	public Block[,,] block;
	public List<block_log> b_log = new List<block_log>();

	public GameObject[] canvas = new GameObject[(int)Define.CANVAS_NUM.MAX_SIZE];
	// Start is called before the first frame update
	void Start()
    {
		//stage_size.Set(5, 5, 5);
		block = new Block[stage_size.z, stage_size.y, stage_size.x];


		//オブジェクト生成
		for (int z = 0; z < stage_size.z; z++)
		{
			for (int y = 0; y < stage_size.y; y++)
			{
				for (int x = 0; x < stage_size.x; x++)
				{
					block[z, y, x].draw_frag = true;
					block[z, y, x].obj = Instantiate(draw_obj, new Vector3(0.0f, 0.0f, 0.0f), Quaternion.identity);
					block[z, y, x].obj.transform.localScale = transform.localScale;
					block[z, y, x].obj.transform.parent = transform;
					block[z, y, x].obj.transform.localPosition = new Vector3((1.0f * x) - (stage_size.x / 2), (1.0f * y) - (stage_size.y / 2), (1.0f * z) - (stage_size.z / 2));
					block_mgr mgr = block[z, y, x].obj.GetComponent<block_mgr>();
					mgr.block_mat = mat;
					mgr.data = block[z, y, x];
					mgr.index = new Vector3Int(x, y, z);
				}
			}
		}
	}

    // Update is called once per frame
    void Update()
    {
		ray = m_camera.ScreenPointToRay(Input.mousePosition);

		RaycastHit hit;
		if (Physics.Raycast(ray, out hit))
		{
			GameObject obj = hit.collider.gameObject;
			obj.GetComponent<block_mgr>().hit_frag = true;


			//置く
			if (Input.GetMouseButtonDown(0))
			{
				Vector3 inst = hit.point - hit.collider.gameObject.transform.localPosition;
				block_mgr mgr = obj.GetComponent<block_mgr>();
				Vector3Int index_pos = hit.collider.gameObject.GetComponent<block_mgr>().index;

				if(inst.x >= 0.5)
				{
					Vector3Int set_index = new Vector3Int(index_pos.x + 1, index_pos.y, index_pos.z);
					if (set_index.x < stage_size.x && !block[set_index.z, set_index.y, set_index.x].draw_frag)
					{
						set_block(set_index);

					}
				}
				else if (inst.x <= -0.5)
				{
					Vector3Int set_index = new Vector3Int(index_pos.x - 1, index_pos.y, index_pos.z);
					if (set_index.x >= 0 && !block[set_index.z, set_index.y, set_index.x].draw_frag)
					{
						set_block(set_index);

					}
				}
				else if (inst.y >= 0.5)
				{
					Vector3Int set_index = new Vector3Int(index_pos.x, index_pos.y + 1, index_pos.z);
					if (set_index.y < stage_size.y && !block[set_index.z, set_index.y, set_index.x].draw_frag)
					{
						set_block(set_index);

					}
				}
				else if (inst.y <= -0.5)
				{
					Vector3Int set_index = new Vector3Int(index_pos.x, index_pos.y - 1, index_pos.z);
					if (set_index.y >= 0 && !block[set_index.z, set_index.y, set_index.x].draw_frag)
					{
						set_block(set_index);

					}
				}
				else if (inst.z >= 0.5)
				{
					Vector3Int set_index = new Vector3Int(index_pos.x, index_pos.y, index_pos.z + 1);
					if (set_index.z < stage_size.y && !block[set_index.z, set_index.y, set_index.x].draw_frag)
					{
						set_block(set_index);

					}
				}
				else if (inst.z <= -0.5)
				{
					Vector3Int set_index = new Vector3Int(index_pos.x, index_pos.y, index_pos.z - 1);
					if (set_index.z >= 0 && !block[set_index.z, set_index.y, set_index.x].draw_frag)
					{
						set_block(set_index);

					}
				}




				//block[index_pos.z, index_pos.y, index_pos.x].draw_frag = false;
				//Destroy(hit.collider.gameObject);

			}

			//削る
			if (Input.GetMouseButtonDown(1))
			{

				block_mgr mgr = obj.GetComponent<block_mgr>();
				Vector3Int index_pos = hit.collider.gameObject.GetComponent<block_mgr>().index;
				block[index_pos.z, index_pos.y, index_pos.x].draw_frag = false;
				b_log.Add(new block_log(true, index_pos));
				Destroy(hit.collider.gameObject);
				
			}
			//Debug.Log(hit.collider.gameObject.transform.position);
		}


		if(b_log.Count > 20)
		{
			b_log.RemoveAt(0);
		}
	}

	private void set_block(Vector3Int set_index)
	{
		b_log.Add(new block_log(false,set_index));
		block[set_index.z, set_index.y, set_index.x].draw_frag = true;
		block[set_index.z, set_index.y, set_index.x].obj = Instantiate(draw_obj, new Vector3(0.0f, 0.0f, 0.0f), Quaternion.identity);
		block[set_index.z, set_index.y, set_index.x].obj.transform.localScale = transform.localScale;
		block[set_index.z, set_index.y, set_index.x].obj.transform.parent = transform;
		block[set_index.z, set_index.y, set_index.x].obj.transform.localPosition = new Vector3((1.0f * set_index.x) - (stage_size.x / 2), (1.0f * set_index.y) - (stage_size.y / 2), (1.0f * set_index.z) - (stage_size.z / 2));
		block_mgr mgr_c = block[set_index.z, set_index.y, set_index.x].obj.GetComponent<block_mgr>();
		mgr_c.block_mat = mat;
		mgr_c.data = block[set_index.z, set_index.y, set_index.x];
		mgr_c.index = new Vector3Int(set_index.x, set_index.y, set_index.z);
	}

	public void save()
	{
		FileStream fs = new FileStream("save",
			FileMode.Create,
			FileAccess.Write);
		BinaryWriter bw = new BinaryWriter(fs);

		//バージョン
		bw.Write(Define.VERSION);

		//サイズ
		bw.Write(stage_size.x);
		bw.Write(stage_size.y);
		bw.Write(stage_size.z);

		//ブロック
		for (int z = 0; z < stage_size.z; z++)
		{
			for (int y = 0; y < stage_size.y; y++)
			{
				for (int x = 0; x < stage_size.x; x++)
				{
					if(block[z, y, x].draw_frag)
					{
						bw.Write(true);
						bw.Write(true);
					}
					else
					{
						bw.Write(false);
						bw.Write(true);
					}
					
					//bw.Write(block[z, y, x].hint);

				}
			}
		}

		fs.Close();
	}

	public void back()
	{
		int max_index = b_log.Count - 1;

		if (max_index < 0) return;
		//生成
		if (b_log[max_index].del_frag)
		{
			block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x].draw_frag = true;
			block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x].obj = Instantiate(draw_obj, new Vector3(0.0f, 0.0f, 0.0f), Quaternion.identity);
			block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x].obj.transform.localScale = transform.localScale;
			block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x].obj.transform.parent = transform;
			block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x].obj.transform.localPosition = new Vector3((1.0f * b_log[max_index].index_pos.x) - (stage_size.x / 2), (1.0f * b_log[max_index].index_pos.y) - (stage_size.y / 2), (1.0f * b_log[max_index].index_pos.z) - (stage_size.z / 2));
			block_mgr mgr_c = block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x].obj.GetComponent<block_mgr>();
			mgr_c.block_mat = mat;
			mgr_c.data = block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x];
			mgr_c.index = new Vector3Int(b_log[max_index].index_pos.x, b_log[max_index].index_pos.y, b_log[max_index].index_pos.z);
		}
		else
		{
			//block_mgr mgr = obj.GetComponent<block_mgr>();
			//Vector3Int index_pos = hit.collider.gameObject.GetComponent<block_mgr>().index;
			block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x].draw_frag = false;
			Destroy(block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x].obj);
		}
		b_log.RemoveAt(max_index);
	}
	public void change_window(int num)
	{
		for(int i = 0; i < (int)Define.CANVAS_NUM.MAX_SIZE; i++)
		{
			canvas[i].SetActive(false);
		}
		canvas[num].SetActive(true);
	}
}
