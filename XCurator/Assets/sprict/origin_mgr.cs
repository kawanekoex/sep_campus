using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Common;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

public class origin_mgr : MonoBehaviour
{
	public Vector3Int stage_size = new Vector3Int(10, 10, 10);
	[SerializeField]
	private GameObject draw_obj;
	[SerializeField]
	private GameObject ef_obj;
	[SerializeField]
	private GameObject ef_b_obj;
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

		//block[0, 0, 0].correct = false;
		//block[1, 0, 0].correct = true;
		//miss_count = 0;
		//correct_count = 0;
		////ヒント判定
		//for (int z = 0; z < stage_size.z; z++)
		//{
		//	for (int y = 0; y < stage_size.y; y++)
		//	{
		//		for (int x = 0; x < stage_size.x; x++)
		//		{
		//			hint_counter(new Vector3Int(x, y, z));
		//			block[z,y,x].draw_frag = true;
		//		}

		//	}
		//}


		////オブジェクト生成
		//for (int z = 0; z < stage_size.z; z++)
		//{
		//	for (int y = 0; y < stage_size.y; y++)
		//	{
		//		for (int x = 0; x < stage_size.x; x++)
		//		{

		//			if (block[z, y, x].draw_frag)
		//			{

		//				block[z,y,x].obj = Instantiate(draw_obj, new Vector3(0.0f, 0.0f, 0.0f), Quaternion.identity);
		//				block[z, y, x].obj.transform.localScale = transform.localScale;
		//				block[z, y, x].obj.transform.parent = transform;
		//				block[z, y, x].obj.transform.localPosition = new Vector3((1.0f * x) - (stage_size.x / 2), (1.0f * y) - (stage_size.y / 2), (1.0f * z) - (stage_size.z / 2));
		//				block_mgr mgr = block[z, y, x].obj.GetComponent<block_mgr>();
		//				mgr.block_mat = num_mat[block[z, y, x].hint];
		//				mgr.data = block[z, y, x];
		//				mgr.index = new Vector3Int(x, y, z);
		//				if (mgr.data.correct)
		//				{
		//					correct_count++;
		//				}
		//				else
		//				{
		//					miss_count++;
		//				}
		//			}
		//		}
		//	}
		//}

		load();


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
				Instantiate(ef_obj, hit.point, Quaternion.identity);
				//Instantiate(ef_b_obj, hit.point, Quaternion.identity);
				block_mgr mgr = obj.GetComponent<block_mgr>();
				if (!mgr.data.correct)
				{
					Vector3Int index_pos = hit.collider.gameObject.GetComponent<block_mgr>().index;
					block[index_pos.z, index_pos.y, index_pos.x].draw_frag = false;
					Instantiate(ef_b_obj, hit.collider.gameObject.transform.position, hit.collider.gameObject.transform.rotation);
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
					bw.Write(block[z, y, x].correct);
					bw.Write(block[z, y, x].draw_frag);
					//bw.Write(block[z, y, x].hint);

				}
			}
		}
					
		fs.Close();
	}

	public void load()
	{
		//オブジェクト削除
		for (int z = 0; z < stage_size.z; z++)
		{
			for (int y = 0; y < stage_size.y; y++)
			{
				for (int x = 0; x < stage_size.x; x++)
				{
					Destroy(block[z, y, x].obj);
				}
			}
		}
		//変数初期化
		correct_count = 0;
		miss_count = 0;
		transform.position = Vector3.zero;
		transform.eulerAngles = Vector3.zero;
		//配列解放
		block = null;

		FileStream fs = new FileStream("save",
			FileMode.Open,
			FileAccess.Read);
		BinaryReader br = new BinaryReader(fs);

		if (Define.VERSION != br.ReadInt32()) return;
		stage_size.Set(br.ReadInt32(), br.ReadInt32(), br.ReadInt32());

		//ブロック
		block = new Block[stage_size.z, stage_size.y, stage_size.x];
		for (int z = 0; z < stage_size.z; z++)
		{
			for (int y = 0; y < stage_size.y; y++)
			{
				for (int x = 0; x < stage_size.x; x++)
				{

					block[z, y, x].correct = br.ReadBoolean();
					block[z, y, x].draw_frag = br.ReadBoolean();
					//block[z, y, x].hint = br.ReadInt32();

					//オブジェクト生成
					if (block[z, y, x].draw_frag)
					{

						block[z, y, x].obj = Instantiate(draw_obj, new Vector3(0.0f, 0.0f, 0.0f), Quaternion.identity);
						block[z, y, x].obj.transform.localScale = transform.localScale;
						block[z, y, x].obj.transform.parent = transform;
						block[z, y, x].obj.transform.localPosition = new Vector3((1.0f * x) - (stage_size.x / 2), (1.0f * y) - (stage_size.y / 2), (1.0f * z) - (stage_size.z / 2));
						block_mgr mgr = block[z, y, x].obj.GetComponent<block_mgr>();
						
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

		//ヒント判定
		for (int z = 0; z < stage_size.z; z++)
		{
			for (int y = 0; y < stage_size.y; y++)
			{
				for (int x = 0; x < stage_size.x; x++)
				{
					block_mgr mgr = block[z, y, x].obj.GetComponent<block_mgr>();
					hint_counter(new Vector3Int(x, y, z));
					mgr.block_mat = num_mat[block[z, y, x].hint];
				}

			}
		}
		//k.correct = br.ReadBoolean();
		//k.draw_frag = br.ReadBoolean();

		fs.Close();
	}
}
