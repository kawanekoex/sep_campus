using DG.Tweening;
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class button_mgr : MonoBehaviour
{
	[SerializeField]
	private CanvasGroup canvasGroup;

	public string sceneName;

	bool frag = false;
	// Start is called before the first frame update
	void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
		
	}
	public void on_buteon()
	{
		transform.DOPunchScale(new Vector3(0.1f, 0.1f,0f),1f);
		StartCoroutine(ExecuteChangeScene());
	}

	IEnumerator ExecuteChangeScene()
	{
		while (canvasGroup.alpha > 0)
		{
			canvasGroup.alpha -= Time.deltaTime;
			yield return null;
		}
		canvasGroup.alpha = 0;

		SceneManager.LoadScene(sceneName);
		yield break;
	}
}
