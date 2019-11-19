using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ui_mgr : MonoBehaviour
{
	public GameObject text_obj;
	private Text text;
	private origin_mgr mgr;
    // Start is called before the first frame update
    void Start()
    {
		text = text_obj.GetComponent<Text>();
		mgr = gameObject.GetComponent<origin_mgr>();
    }

    // Update is called once per frame
    void Update()
    {
		text.text = "残り" + mgr.miss_count + "個";

    }
}
