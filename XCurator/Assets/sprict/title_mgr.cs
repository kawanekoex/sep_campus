using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class title_mgr : MonoBehaviour
{
	private int window_num;
	[SerializeField]
	private GameObject[] canves;
	[SerializeField]
	private Text[] text = new Text[3];

	// Start is called before the first frame update
	void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
		text[0].text = "X = " + edito_mgr.stage_size.x;
		text[1].text = "Y = " + edito_mgr.stage_size.y;
		text[2].text = "Z = " + edito_mgr.stage_size.z;
	}

	
	public void on_x()
	{
		edito_mgr.stage_size.x++;

		if(edito_mgr.stage_size.x > 100)
		{
			edito_mgr.stage_size.x = 100;
		}
	}
	public void off_x()
	{
		edito_mgr.stage_size.x--;
		if (edito_mgr.stage_size.x < 0)
		{
			edito_mgr.stage_size.x = 0;
		}
	}
	public void on_y()
	{
		edito_mgr.stage_size.y++;

		if (edito_mgr.stage_size.y > 100)
		{
			edito_mgr.stage_size.y = 100;
		}
	}
	public void off_y()
	{
		edito_mgr.stage_size.y--;
		if (edito_mgr.stage_size.y < 0)
		{
			edito_mgr.stage_size.y = 0;
		}
	}
	public void on_z()
	{
		edito_mgr.stage_size.z++;

		if (edito_mgr.stage_size.z > 100)
		{
			edito_mgr.stage_size.z = 100;
		}
	}
	public void off_z()
	{
		edito_mgr.stage_size.z--;
		if (edito_mgr.stage_size.z < 0)
		{
			edito_mgr.stage_size.z = 0;
		}
	}
}
