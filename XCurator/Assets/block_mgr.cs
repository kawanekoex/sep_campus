using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class block_mgr : MonoBehaviour
{
    public Vector2Int index;
    public Material block_mat;
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
