using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Common;

public class key_input : MonoBehaviour
{
	public Camera camera = new Camera();
	private origin_mgr mgr;
	private bool[] button_frag = new bool[4];
	
	// Start is called before the first frame update
	void Start()
    {
		mgr = gameObject.GetComponent<origin_mgr>();
    }

    // Update is called once per frame
    void Update()
    {
		//回転
		//上
		if (Input.GetKey(KeyCode.W) || button_frag[(int)Define.DIRECTION_NUM.UP])
		{
			transform.Rotate(new Vector3(-5, 0, 0), Space.World);
		}
		//下
		if (Input.GetKey(KeyCode.S) || button_frag[(int)Define.DIRECTION_NUM.DOWN])
		{
			transform.Rotate(new Vector3(5, 0, 0), Space.World);
		}
		//右
		if (Input.GetKey(KeyCode.D) || button_frag[(int)Define.DIRECTION_NUM.RIGHT])
		{
			transform.Rotate(new Vector3(0, -5, 0), Space.World);
		}
		//下
		if (Input.GetKey(KeyCode.A) || button_frag[(int)Define.DIRECTION_NUM.LEFT])
		{
			transform.Rotate(new Vector3(0, 5, 0), Space.World);
		}

		//拡縮
		float scroll = Input.GetAxis("Mouse ScrollWheel");
		Vector3 pos_inst = camera.transform.position + new Vector3(0, 0, -scroll * Define.ZOOM_SPEED);
		if (-scroll > 0 && pos_inst.z > Define.ZOOM_MAX)
		{
			pos_inst.z = Define.ZOOM_MAX;
		}
		else if (-scroll < 0 && pos_inst.z < Define.ZOOM_MIN)
		{
			pos_inst.z = Define.ZOOM_MIN;
		}
		camera.transform.position = pos_inst;

		mgr.ray = camera.ScreenPointToRay(Input.mousePosition);
	}

	public void up_button()
	{
		button_frag[(int)Define.DIRECTION_NUM.UP] = true;
	}
	public void down_button()
	{
		button_frag[(int)Define.DIRECTION_NUM.DOWN] = true;
	}
	public void right_button()
	{
		button_frag[(int)Define.DIRECTION_NUM.RIGHT] = true;
	}
	public void left_button()
	{
		button_frag[(int)Define.DIRECTION_NUM.LEFT] = true;
	}

	public void up_button_up()
	{
		button_frag[(int)Define.DIRECTION_NUM.UP] = false;
	}
	public void down_button_up()
	{
		button_frag[(int)Define.DIRECTION_NUM.DOWN] = false;
	}
	public void right_button_up()
	{
		button_frag[(int)Define.DIRECTION_NUM.RIGHT] = false;
	}
	public void left_button_up()
	{
		button_frag[(int)Define.DIRECTION_NUM.LEFT] = false;
	}
}
