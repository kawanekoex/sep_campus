using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class create_mesh : MonoBehaviour
{
	public Vector3[] draw_vertices = new Vector3[3];
	public Vector3 direction = new Vector3();
	public bool frag;

	// Start is called before the first frame update
	void Start()
    {
		Mesh mesh = new Mesh();
		mesh.vertices = draw_vertices;
		mesh.triangles = new int[] { 0,1,2};
		mesh.RecalculateNormals();

		var filter = GetComponent<MeshFilter>();

		filter.sharedMesh = mesh;

	}

    // Update is called once per frame
    void Update()
    {
		Vector3 num = new Vector3();
		float value = Time.deltaTime / 10;
		if (direction.x != 0)
		{
			num = new Vector3(0, value, value) * 5;
			transform.localScale -= num;
		}
		else if (direction.y != 0)
		{
			num = new Vector3(value, 0, value) * 5;
			transform.localScale -= num;
		}
		else if (direction.z != 0)
		{
			num = new Vector3(value, value, 0) * 5;
			transform.localScale -= num;
		}


		
		//拡縮
		if (transform.localScale.x < 0) transform.localScale = new Vector3(0, transform.localScale.y, transform.localScale.z);
		if (transform.localScale.y < 0) transform.localScale = new Vector3(transform.localScale.x, 0, transform.localScale.z);
		if (transform.localScale.z < 0) transform.localScale = new Vector3(transform.localScale.x, transform.localScale.y, 0);
		if (frag)
		{
			transform.position += num / 4.0f;
		}
		else
		{
			transform.position -= num / 4.0f;
		}

		//移動
		transform.position += direction * value;

		//アルファ減少
		Renderer renderer = GetComponent<Renderer>();

		Color c = renderer.material.color;
		c.a -= value * 10;
		renderer.material.color = c;
		//削除
		if (transform.localScale == Vector3.zero || renderer.material.color.a <= 0)
		{
			Destroy(this.gameObject);
		}
	}
}
