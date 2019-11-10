using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Common;

public class block_mgr : MonoBehaviour
{
    public Vector2Int index;
    public Material block_mat;
	public Block data;
	public bool hit_frag;

	private MeshRenderer meshRenderer;
    // Start is called before the first frame update
    void Start()
    {
		meshRenderer = GetComponent<MeshRenderer>();

		meshRenderer.material = block_mat;
		
    }

    // Update is called once per frame
    void Update()
    {
		if (hit_frag)
		{
			meshRenderer.material.color = new Color(1, 1, 1, 0.5f);
		}
		else
		{
			meshRenderer.material.color = new Color(1, 1, 1, 1);
		}


		hit_frag = false;
    }
}
