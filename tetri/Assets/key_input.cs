using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Common;

public class key_input : MonoBehaviour
{
    //[SerializeField]
    public GameObject mgr;
    private List<Define.ACT> act = new List<Define.ACT>();
    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        act.Clear();
        if (Input.GetKey(KeyCode.S))
        {
            act.Add(Define.ACT.DOWN);
        }

        if (Input.GetKeyDown(KeyCode.A))
        {
            act.Add(Define.ACT.LEFT);
        }

        if (Input.GetKeyDown(KeyCode.D))
        {
            act.Add(Define.ACT.RIGHT);
        }

        if (Input.GetKeyDown(KeyCode.K))
        {
            act.Add(Define.ACT.LEFT_ROLL);
        }

        if (Input.GetKeyDown(KeyCode.L))
        {
            act.Add(Define.ACT.RIGHT_ROLL);
        }

        if (Input.GetKeyDown(KeyCode.Q))
        {
            act.Add(Define.ACT.HOLD);
        }
        mgr.GetComponent<Tetris_mgr>().act = new List<Define.ACT>(act);
    }
}
