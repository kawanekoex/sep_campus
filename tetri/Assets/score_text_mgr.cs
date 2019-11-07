using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class score_text_mgr : MonoBehaviour
{
    public int score;
    private int draw_score;
    // Start is called before the first frame update
    void Start()
    {
        score = 0;
        draw_score = 0;
    }

    // Update is called once per frame
    void Update()
    {
        //テキスト
        if (score > draw_score + 1000)
        {
            draw_score += 10;
        }
        else if (score > draw_score + 100)
        {
            draw_score += 5;
        }
        else if (score > draw_score)
        {
            draw_score++;
        }
        else
        {
            draw_score = score;
        }




        float score_inst = draw_score;
        int keta = 0;
        while (score_inst >= 1.0f)
        {
            keta++;
            score_inst /= 10.0f;
        }

        Text score_text = GetComponent<Text>();
        score_text.text = "";
        for (int i = 0; i < 14 - keta; i++)
        {
            score_text.text += "0";
        }
        score_text.text += draw_score;
    }
}
