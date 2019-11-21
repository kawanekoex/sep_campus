using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class camera_mgr : MonoBehaviour
{
	public float move_speed;
	public float cursor_speed;
	public Transform verRot;
	public Transform horRot;
	// Start is called before the first frame update
	void Start()
    {
		verRot = transform.parent;
		horRot = GetComponent<Transform>();
	}

    // Update is called once per frame
    void Update()
    {
		//移動
		if (Input.GetKey(KeyCode.W))
		{
			verRot.transform.localPosition += transform.forward * move_speed * Time.deltaTime;
		}
		if (Input.GetKey(KeyCode.S))
		{
			verRot.transform.localPosition -= transform.forward * move_speed * Time.deltaTime;
		}
		if (Input.GetKey(KeyCode.D))
		{
			verRot.transform.localPosition += transform.right * move_speed * Time.deltaTime;
		}
		if (Input.GetKey(KeyCode.A))
		{
			verRot.transform.localPosition -= transform.right * move_speed * Time.deltaTime;
		}
		
		if (Input.GetKey(KeyCode.Space))
		{
			Cursor.visible = false;
			Cursor.lockState = CursorLockMode.Locked;
			//Cursor.lockState = CursorLockMode.Confined;
			float X_Rotation = Input.GetAxis("Mouse X");
			float Y_Rotation = Input.GetAxis("Mouse Y");
			verRot.transform.Rotate(0, X_Rotation * cursor_speed, 0);
			Vector3 v_inst = horRot.transform.rotation.eulerAngles;
			horRot.transform.Rotate(-Y_Rotation * cursor_speed, 0, 0);
			if(/*Y_Rotation < 0 && */transform.rotation.eulerAngles.x > 40.0f && transform.rotation.eulerAngles.x < 280.0f)
			{
				transform.eulerAngles = v_inst;
			}
			//if (Y_Rotation > 0 && transform.rotation.eulerAngles.x > 40.0f && transform.rotation.eulerAngles.x < 280.0f)
			//{
			//	transform.eulerAngles = v_inst;
			//}
			//if(horRot.transform.Rotate)
			//Debug.Log(Y_Rotation);
			//Debug.Log(transform.rotation.eulerAngles);
		}
		else
		{
			Cursor.visible = true;
			Cursor.lockState = CursorLockMode.None;
		}
	}
}
