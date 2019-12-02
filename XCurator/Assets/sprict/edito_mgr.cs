using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Common;
using System.IO;





public class edito_mgr : MonoBehaviour
{
	public Ray ray;         //レイキャスト判定
	public static Vector3Int stage_size = new Vector3Int(5, 5, 5);
	private Vector3Int max_size = new Vector3Int(0, 0, 0);
	private Vector3Int min_size = new Vector3Int(0, 0, 0);
	public Camera m_camera;
	public Material mat;
	[SerializeField]
	private GameObject draw_obj;
	//public Block[,,] block;

	//public List<Block> block = new List<Block>();

	public List<block_log> b_log = new List<block_log>();

	public GameObject[] canvas = new GameObject[(int)Define.CANVAS_NUM.MAX_SIZE];

	private Define.MODE_NUM mode = Define.MODE_NUM.MAIN;
	private Color c = Color.white;
	// Start is called before the first frame update
	void Start()
	{
		//stage_size.Set(5, 5, 5);
		//block = new Block[stage_size.z, stage_size.y, stage_size.x];


		////オブジェクト生成
		//for (int z = 0; z < stage_size.z; z++)
		//{
		//	for (int y = 0; y < stage_size.y; y++)
		//	{
		//		for (int x = 0; x < stage_size.x; x++)
		//		{
		//			block[z, y, x].draw_frag = true;
		//			block[z, y, x].obj = Instantiate(draw_obj, new Vector3(0.0f, 0.0f, 0.0f), Quaternion.identity);
		//			block[z, y, x].obj.transform.localScale = transform.localScale;
		//			block[z, y, x].obj.transform.parent = transform;
		//			block[z, y, x].obj.transform.localPosition = new Vector3((1.0f * x) - (stage_size.x / 2), (1.0f * y) - (stage_size.y / 2), (1.0f * z) - (stage_size.z / 2));
		//			block_mgr mgr = block[z, y, x].obj.GetComponent<block_mgr>();
		//			mgr.block_mat = mat;
		//			mgr.data = block[z, y, x];
		//			mgr.index = new Vector3Int(x, y, z);
		//		}
		//	}
		//}

		//中心設定



		//ブロック生成
		Block b = new Block();
		b.draw_frag = true;
		b.id = 0;
		b.obj = Instantiate(draw_obj, new Vector3(0, 0, 0), Quaternion.identity);
		b.obj.transform.localScale = transform.localScale;
		b.obj.transform.parent = transform;
		b.obj.transform.localPosition = new Vector3(0, 0, 0);
		block_mgr b_m = b.obj.GetComponent<block_mgr>();
		b_m.block_mat = mat;
		b_m.index = new Vector3Int(0, 0, 0);
		b_m.data = b;



	}

	// Update is called once per frame
	void Update()
	{
		ray = m_camera.ScreenPointToRay(Input.mousePosition);

		RaycastHit hit;
		if (Physics.Raycast(ray, out hit))
		{
			GameObject obj = hit.collider.gameObject;
			block_mgr mgr = obj.GetComponent<block_mgr>();
			mgr.hit_frag = true;
			Block b = mgr.data;

			if (mode == Define.MODE_NUM.MAIN)
			{
				//置く
				if (Input.GetMouseButtonDown(0))
				{
					Vector3 inst = hit.point - hit.collider.gameObject.transform.localPosition;

					Vector3Int index_pos = mgr.index;
					//int list_index_pos = mgr.list_index;

					if (inst.x >= 0.5)
					{
						Vector3Int set_index = new Vector3Int(index_pos.x + 1, index_pos.y, index_pos.z);
						//if (set_index.x < stage_size.x && !block[set_index.z, set_index.y, set_index.x].draw_frag)
						//{
						//	set_block(set_index);

						//}
						if (b.draw_frag)
						{
							set_block2(1, set_index);
						}
					}
					else if (inst.x <= -0.5)
					{
						Vector3Int set_index = new Vector3Int(index_pos.x - 1, index_pos.y, index_pos.z);
						//if (set_index.x >= 0 && !block[set_index.z, set_index.y, set_index.x].draw_frag)
						//{
						//	set_block(set_index);

						//}
						if (b.draw_frag)
						{
							set_block2(1, set_index);
						}
					}
					else if (inst.y >= 0.5)
					{
						Vector3Int set_index = new Vector3Int(index_pos.x, index_pos.y + 1, index_pos.z);
						//if (set_index.y < stage_size.y && !block[set_index.z, set_index.y, set_index.x].draw_frag)
						//{
						//	set_block(set_index);

						//}
						if (b.draw_frag)
						{
							set_block2(1, set_index);
						}
					}
					else if (inst.y <= -0.5)
					{
						Vector3Int set_index = new Vector3Int(index_pos.x, index_pos.y - 1, index_pos.z);
						//if (set_index.y >= 0 && !block[set_index.z, set_index.y, set_index.x].draw_frag)
						//{
						//	set_block(set_index);

						//}
						if (b.draw_frag)
						{
							set_block2(1, set_index);
						}
					}
					else if (inst.z >= 0.5)
					{
						Vector3Int set_index = new Vector3Int(index_pos.x, index_pos.y, index_pos.z + 1);
						//if (set_index.z < stage_size.y && !block[set_index.z, set_index.y, set_index.x].draw_frag)
						//{
						//	set_block(set_index);

						//}
						if (b.draw_frag)
						{
							set_block2(1, set_index);
						}
					}
					else if (inst.z <= -0.5)
					{
						Vector3Int set_index = new Vector3Int(index_pos.x, index_pos.y, index_pos.z - 1);
						//if (set_index.z >= 0 && !block[set_index.z, set_index.y, set_index.x].draw_frag)
						//{
						//	set_block(set_index);

						//}
						if (b.draw_frag)
						{
							set_block2(1, set_index);
						}
					}

					//block[index_pos.z, index_pos.y, index_pos.x].draw_frag = false;
					//Destroy(hit.collider.gameObject);

				}

				//削る
				if (Input.GetMouseButtonDown(1))
				{
					if (b.id != 0)
					{
						Vector3Int index_pos = mgr.index;
						//int list_index_pos = mgr.list_index;

						b_log.Add(new block_log(true, index_pos, b));
						Destroy(hit.collider.gameObject);
					}
				}
			}
			else if (mode == Define.MODE_NUM.MAT_SET)
			{
				//色変更
				if (Input.GetMouseButtonDown(0))
				{
					//int index_pos = hit.collider.gameObject.GetComponent<block_mgr>().list_index;
					b.obj.GetComponent<MeshRenderer>().material.color = c;
					//hit.collider.gameObject.GetComponent<MeshRenderer>().material.color = c;
				}
			}
			//Debug.Log(hit.collider.gameObject.transform.position);
		}


		if (b_log.Count > 20)
		{
			b_log.RemoveAt(0);
		}
	}

	private void set_block(Vector3Int set_index)
	{
		//b_log.Add(new block_log(false,set_index));
		//block[set_index.z, set_index.y, set_index.x].draw_frag = true;
		//block[set_index.z, set_index.y, set_index.x].obj = Instantiate(draw_obj, new Vector3(0.0f, 0.0f, 0.0f), Quaternion.identity);
		//block[set_index.z, set_index.y, set_index.x].obj.transform.localScale = transform.localScale;
		//block[set_index.z, set_index.y, set_index.x].obj.transform.parent = transform;
		//block[set_index.z, set_index.y, set_index.x].obj.transform.localPosition = new Vector3((1.0f * set_index.x) - (stage_size.x / 2), (1.0f * set_index.y) - (stage_size.y / 2), (1.0f * set_index.z) - (stage_size.z / 2));
		//block_mgr mgr_c = block[set_index.z, set_index.y, set_index.x].obj.GetComponent<block_mgr>();
		//mgr_c.block_mat = mat;
		//mgr_c.data = block[set_index.z, set_index.y, set_index.x];
		//mgr_c.index = new Vector3Int(set_index.x, set_index.y, set_index.z);
	}

	private void set_block2(int id, Vector3Int set_index)
	{
		//サイズ更新	
		if (set_index.x > max_size.x) max_size.x = set_index.x;
		if (set_index.y > max_size.y) max_size.y = set_index.y;
		if (set_index.z > max_size.z) max_size.z = set_index.z;

		if (set_index.x < min_size.x) min_size.x = set_index.x;
		if (set_index.y < min_size.x) min_size.y = set_index.y;
		if (set_index.z < min_size.x) min_size.z = set_index.z;



		//ブロック生成
		Block b = new Block();
		b.draw_frag = true;
		b.id = id;
		b.obj = Instantiate(draw_obj, new Vector3(0, 0, 0), Quaternion.identity);
		b.obj.transform.localScale = transform.localScale;
		b.obj.transform.parent = transform;
		b.obj.transform.localPosition = new Vector3(set_index.x * Define.BLOCK_SIZE, set_index.y * Define.BLOCK_SIZE, set_index.z * Define.BLOCK_SIZE);
		block_mgr b_m = b.obj.GetComponent<block_mgr>();
		b_m.block_mat = mat;
		b_m.index = set_index;
		b_m.data = b;
		//ログ追加
		b_log.Add(new block_log(false, set_index, b));
	}

	public void save()
	{
		//FileStream fs = new FileStream("save",
		//	FileMode.Create,
		//	FileAccess.Write);
		//BinaryWriter bw = new BinaryWriter(fs);

		////バージョン
		//bw.Write(Define.VERSION);

		////サイズ
		//bw.Write(stage_size.x);
		//bw.Write(stage_size.y);
		//bw.Write(stage_size.z);

		////ブロック
		//for (int z = 0; z < stage_size.z; z++)
		//{
		//	for (int y = 0; y < stage_size.y; y++)
		//	{
		//		for (int x = 0; x < stage_size.x; x++)
		//		{
		//			if(block[z, y, x].draw_frag)
		//			{
		//				bw.Write(true);
		//				bw.Write(true);
		//			}
		//			else
		//			{
		//				bw.Write(false);
		//				bw.Write(true);
		//			}

		//			//bw.Write(block[z, y, x].hint);

		//		}
		//	}
		//}

		//fs.Close();
	}

	public void save2()
	{
		FileStream fs = new FileStream("e_save",
			FileMode.Create,
			FileAccess.Write);
		BinaryWriter bw = new BinaryWriter(fs);

		//バージョン
		bw.Write(Define.VERSION);

		//サイズ
		//bw.Write(max_size.x);
		//bw.Write(max_size.y);
		//bw.Write(max_size.z);

		//bw.Write(min_size.x);
		//bw.Write(min_size.y);
		//bw.Write(min_size.z);

		bw.Write(transform.childCount);

		foreach (Transform child in transform)
		{
			Block block = child.GetComponent<block_mgr>().data;
			Vector3Int pos = block.obj.GetComponent<block_mgr>().index;
			bw.Write(block.id);
			bw.Write(pos.x);
			bw.Write(pos.y);
			bw.Write(pos.z);
		}
		fs.Close();
	}

	public void game_date_save()
	{
		stage_size.x = (max_size.x - min_size.x) + 1;
		stage_size.y = (max_size.y - min_size.y) + 1;
		stage_size.z = (max_size.z - min_size.z) + 1;

		FileStream fs = new FileStream("Assets/save",
			FileMode.Create,
			FileAccess.Write);
		BinaryWriter bw = new BinaryWriter(fs);
		bw.Write(Define.VERSION);
		bw.Write(stage_size.x);
		bw.Write(stage_size.y);
		bw.Write(stage_size.z);

		Block[,,] block = new Block[stage_size.z, stage_size.y, stage_size.x];



		foreach (Transform child in transform)
		{
			Block b = child.GetComponent<block_mgr>().data;
			Vector3Int pos = b.obj.GetComponent<block_mgr>().index;
			pos -= min_size;
			block[pos.z, pos.y, pos.x].draw_frag = true;
		}

		for (int z = 0; z < stage_size.z; z++)
		{
			for (int y = 0; y < stage_size.y; y++)
			{
				for (int x = 0; x < stage_size.x; x++)
				{
					if (block[z, y, x].draw_frag)
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

	public void load()
	{
		foreach (Transform child in transform)
		{
			Destroy(child.gameObject);

		}

		max_size = new Vector3Int(0, 0, 0);
		min_size = new Vector3Int(0, 0, 0);

		FileStream fs = new FileStream("e_save",
			FileMode.Open,
			FileAccess.Read);
		BinaryReader br = new BinaryReader(fs);

		if (Define.VERSION != br.ReadInt32()) return;

		int count = br.ReadInt32();

		for(int i = 0; i < count; i++)
		{
			Vector3Int pos = new Vector3Int();
			int id;

			id = br.ReadInt32();
			pos.x = br.ReadInt32();
			pos.y = br.ReadInt32();
			pos.z = br.ReadInt32();

			set_block2(id, pos);
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
			//サイズ更新	
			if (b_log[max_index].index_pos.x > max_size.x) max_size.x = b_log[max_index].index_pos.x;
			if (b_log[max_index].index_pos.y > max_size.y) max_size.y = b_log[max_index].index_pos.y;
			if (b_log[max_index].index_pos.z > max_size.z) max_size.z = b_log[max_index].index_pos.z;

			if (b_log[max_index].index_pos.x < min_size.x) min_size.x = b_log[max_index].index_pos.x;
			if (b_log[max_index].index_pos.y < min_size.x) min_size.y = b_log[max_index].index_pos.y;
			if (b_log[max_index].index_pos.z < min_size.x) min_size.z = b_log[max_index].index_pos.z;



			//ブロック生成
			Block b = new Block();
			b.draw_frag = true;
			b.id = b_log[max_index].date.id;
			b.obj = Instantiate(draw_obj, new Vector3(0, 0, 0), Quaternion.identity);
			b.obj.transform.localScale = transform.localScale;
			b.obj.transform.parent = transform;
			b.obj.transform.localPosition = new Vector3(b_log[max_index].index_pos.x * Define.BLOCK_SIZE, b_log[max_index].index_pos.y * Define.BLOCK_SIZE, b_log[max_index].index_pos.z * Define.BLOCK_SIZE);
			block_mgr b_m = b.obj.GetComponent<block_mgr>();
			b_m.block_mat = mat;
			b_m.index = b_log[max_index].index_pos;
			b_m.data = b;
			//block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x].draw_frag = true;
			//block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x].obj = Instantiate(draw_obj, new Vector3(0.0f, 0.0f, 0.0f), Quaternion.identity);
			//block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x].obj.transform.localScale = transform.localScale;
			//block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x].obj.transform.parent = transform;
			//block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x].obj.transform.localPosition = new Vector3((1.0f * b_log[max_index].index_pos.x) - (stage_size.x / 2), (1.0f * b_log[max_index].index_pos.y) - (stage_size.y / 2), (1.0f * b_log[max_index].index_pos.z) - (stage_size.z / 2));
			//block_mgr mgr_c = block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x].obj.GetComponent<block_mgr>();
			//mgr_c.block_mat = mat;
			//mgr_c.data = block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x];
			//mgr_c.index = new Vector3Int(b_log[max_index].index_pos.x, b_log[max_index].index_pos.y, b_log[max_index].index_pos.z);
		}
		else
		{
			//block_mgr mgr = obj.GetComponent<block_mgr>();
			//Vector3Int index_pos = hit.collider.gameObject.GetComponent<block_mgr>().index;
			//block[b_log[max_index].index_pos.z, b_log[max_index].index_pos.y, b_log[max_index].index_pos.x].draw_frag = false;
			Destroy(b_log[max_index].date.obj);
		}
		b_log.RemoveAt(max_index);
	}
	public void change_window(int num)
	{
		if(num == (int)Define.CANVAS_NUM.MAIN)
		{
			mode = Define.MODE_NUM.MAIN;
		}
		else if(num == (int)Define.CANVAS_NUM.MAT_SET)
		{
			mode = Define.MODE_NUM.MAT_SET;
		}

		for(int i = 0; i < (int)Define.CANVAS_NUM.MAX_SIZE; i++)
		{
			canvas[i].SetActive(false);
		}
		canvas[num].SetActive(true);
	}

	public void collar_set(int s)
	{
		if (s == 0)
		{
			c = Color.white;
		}
		else if (s == -1)
		{
			c = Color.black;
		}
		else if (s == 1)
		{
			c = Color.red;
		}
		else if (s == 2)
		{
			c = Color.green;
		}
		else if (s == 3)
		{
			c = Color.blue;
		}
		
	}
		
}
