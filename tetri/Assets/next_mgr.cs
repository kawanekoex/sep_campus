using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class next_mgr : MonoBehaviour
{
    public GameObject g_mgr;
    public int index;
    private int inst;
    private string[] f_name = new string[7] {
        "Block1",
        "Block2",
        "Block3",
        "Block4",
        "Block5",
        "Block6",
        "Block7"
        };
    // Start is called before the first frame update
    void Start()
    {
        inst = -1;
    }

    // Update is called once per frame
    void Update()
    {
        
        if (g_mgr.GetComponent<Tetris_mgr>().next[index] != inst)
        {
            inst = g_mgr.GetComponent<Tetris_mgr>().next[index];
            GameObject ChildObject;
            ChildObject = transform.GetChild(1).gameObject;

            Destroy(ChildObject);

            GameObject prefab = (GameObject)Resources.Load(f_name[inst]);

            GameObject obj = (GameObject)Instantiate(prefab, transform.position, Quaternion.identity);

            obj.transform.localScale = transform.localScale;
            obj.transform.parent = transform;


        }
    }
}
