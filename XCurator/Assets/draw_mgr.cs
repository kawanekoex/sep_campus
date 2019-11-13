using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class draw_mgr : MonoBehaviour
{
	private origin_mgr mgr;
	public Camera cam;
	// Start is called before the first frame update
	void Start()
    {
		mgr = gameObject.GetComponent<origin_mgr>();
    }

    // Update is called once per frame
    void Update()
    {
        for(int z = 0; z < mgr.stage_size.z; z++)
		{
			for (int y = 0; y < mgr.stage_size.y; y++)
			{
				for (int x = 0; x < mgr.stage_size.x; x++)
				{
					if (!mgr.block[z, y, x].draw_frag)
					{
						continue;
					}
					if (mgr.block[z, y, x].obj.transform.up.z < 0.1f)
					{ 
						//上
						if (y + 1 < mgr.stage_size.y)
						{
							if (!mgr.block[z, y + 1, x].draw_frag)
							{
								mgr.block[z, y, x].obj.SetActive(true);
								continue;
							}
						}
						else
						{
							mgr.block[z, y, x].obj.SetActive(true);
							continue;
						}
					}
					if (mgr.block[z, y, x].obj.transform.up.z > -0.1f)
					{
						//下
						if (y - 1 >= 0)
						{
							if (!mgr.block[z, y - 1, x].draw_frag)
							{
								mgr.block[z, y, x].obj.SetActive(true);
								continue;
							}
						}
						else
						{
							mgr.block[z, y, x].obj.SetActive(true);
							continue;
						}
					}
				

					if (mgr.block[z, y, x].obj.transform.right.z < 0.1f)
					{
						//右
						if (x + 1 < mgr.stage_size.x)
						{
							if (!mgr.block[z, y, x + 1].draw_frag)
							{
								mgr.block[z, y, x].obj.SetActive(true);
								continue;
							}
						}
						else
						{
							mgr.block[z, y, x].obj.SetActive(true);
							continue;
						}
						
					}
					if (mgr.block[z, y, x].obj.transform.right.z > -0.1f)
					{
						//左
						if (x - 1 >= 0)
						{
							if (!mgr.block[z, y, x - 1].draw_frag)
							{
								mgr.block[z, y, x].obj.SetActive(true);
								continue;
							}
						}
						else
						{
							mgr.block[z, y, x].obj.SetActive(true);
							continue;
						}
					}
					if (mgr.block[z, y, x].obj.transform.forward.z < 0.1f)
					{
						//後ろ
						if (z + 1 < mgr.stage_size.z)
						{
							if (!mgr.block[z + 1, y, x].draw_frag)
							{
								mgr.block[z, y, x].obj.SetActive(true);
								continue;
							}
						}
						else
						{
							mgr.block[z, y, x].obj.SetActive(true);
							continue;
						}
					}
					if (mgr.block[z, y, x].obj.transform.forward.z > -0.1f)
					{
						if (z - 1 >= 0)
						{
							if (!mgr.block[z - 1, y, x].draw_frag)
							{
								mgr.block[z, y, x].obj.SetActive(true);
								continue;
							}
						}
						else
						{
							mgr.block[z, y, x].obj.SetActive(true);
							continue;
						}
					}
					mgr.block[z, y, x].obj.SetActive(false);
				}
			}
			
			//z++;
		}
	}
}
