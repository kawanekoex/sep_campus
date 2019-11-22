using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class bg_mgr : MonoBehaviour
{
	Vector2 pos = new Vector2(0,0);

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
		pos.x -= 0.1f * Time.deltaTime;
		pos.y -= 0.1f * Time.deltaTime;
		GetComponent<Renderer>().sharedMaterial.SetTextureOffset("_MainTex", pos);
    }
}
