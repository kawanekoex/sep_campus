using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class color_change : MonoBehaviour
{
    public Color c;
    // Start is called before the first frame update
    void Start()
    {
        GetComponent<Renderer>().material.color = c;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
