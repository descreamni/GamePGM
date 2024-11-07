using UnityEngine;
using UnityEngine.SceneManagement;

public class LoadGame : MonoBehaviour
{
    public string sceneName;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    public void LoadGameScene()
    {
        UIController.gameOver = false;
        SceneManager.LoadScene(sceneName);
        Score.score = 0;
    }
}
