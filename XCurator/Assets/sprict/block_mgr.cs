using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Common;
using DG.Tweening;

public class block_mgr : MonoBehaviour
{
    public Vector3Int index;
    public Material block_mat;
	public Block data;
	public bool hit_frag;

	private MeshRenderer meshRenderer;
	bool do_frag = false;
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
			meshRenderer.material.color = new Color(1, 0.4f, 0.4f, 1.0f);
			if (do_frag == false)
			{
				do_frag = true;
				transform.DOScale(new Vector3(1.1f, 1.1f, 1.1f), 0.3f);
			}

		}
		else
		{
			do_frag = false;
			transform.localScale = Vector3.one;
			meshRenderer.material.color = new Color(1, 1, 1, 1);
		}


		hit_frag = false;
    }
	
}
