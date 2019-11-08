using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Common;

public class sprite_mgr : MonoBehaviour
{
    public Sprite block_spr;
    public Vector2Int index;
    public Color c;
    // Start is called before the first frame update
    void Start()
    {
        GetComponent<SpriteRenderer>().sprite = block_spr;
        GetComponent<SpriteRenderer>().color = c;
    }

    // Update is called once per frame
    void Update()
    {
        GetComponent<SpriteRenderer>().sprite = block_spr;
    }
}
