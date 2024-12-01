using TMPro;
using UnityEngine;

public class Timer : MonoBehaviour
{
    public static float time;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        time = 0;
    }

    // Update is called once per frame
    void Update()
    {
        if(GoalArea.goal == false)
        {
            time += Time.deltaTime;
        }

        int t = Mathf.FloorToInt(time);
        TextMeshProUGUI uiText = GetComponent<TextMeshProUGUI>();
        uiText.text = "Time : " + t.ToString();
    }
}
