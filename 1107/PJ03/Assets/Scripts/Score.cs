using UnityEngine;
using UnityEngine.UI;
public class Score : MonoBehaviour
{
    public static int score;
    private Text txt;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        txt = GetComponent<Text>();    
    }

    // Update is called once per frame
    void Update()
    {
        txt.text = "Score : " + score.ToString();
    }
}
