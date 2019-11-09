using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Common;

public class block_mgr : MonoBehaviour
{
    public Vector2Int index;
    public Material block_mat;
	public Block data;
    // Start is called before the first frame update
    void Start()
    {
        GetComponent<MeshRenderer>().material = block_mat;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
