using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using TMPro;

public class GameResult : MonoBehaviour
{
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    private int highScore;
    public TextMeshProUGUI resultTime;
    public TextMeshProUGUI bestTime;
    public GameObject parts;
    void Start()
    {

        if (PlayerPrefs.HasKey("HighScore"))
        {
            highScore = PlayerPrefs.GetInt("HighScore");
        }
        else
        {
            highScore = 999;
        }
    }

    // Update is called once per frame
    void Update()
    {
        if(GoalArea.goal)
        {
            parts.SetActive(true);
            int result = Mathf.FloorToInt(Timer.time);
            resultTime.text = "ResultTime" + result;
            bestTime.text = "BestTime" + highScore;
            if(highScore > result)
            {
                PlayerPrefs.SetInt("HighScore", result);
            }
        }
    }
    public void OnRetry()
    {
        SceneManager.LoadScene("Main");
    }
}
