using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class obj_mgr : MonoBehaviour
{
    public Vector2Int index;
    public Color c;

    // Start is called before the first frame update
    void Start()
    {
        GetComponent<Renderer>().material.color = c;



    }

    // Update is called once per frame
    void Update()
    {
        GetComponent<Renderer>().material.color = c;
    }
}
