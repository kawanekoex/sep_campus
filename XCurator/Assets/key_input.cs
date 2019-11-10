using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Common;

public class key_input : MonoBehaviour
{
	public Camera camera;
	private origin_mgr mgr;
	
	// Start is called before the first frame update
	void Start()
    {
		mgr = gameObject.GetComponent<origin_mgr>();
    }

    // Update is called once per frame
    void Update()
    {
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

		mgr.ray = camera.ScreenPointToRay(Input.mousePosition);
	}
}
