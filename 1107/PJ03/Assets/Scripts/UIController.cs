using UnityEngine;
using UnityEngine.UI;

public class UIController : MonoBehaviour
{
    public Text text;
    public static bool gameOver;
    public GameObject btn;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        text.enabled = false;
        btn.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
        if (gameOver)
        {
            text.enabled = true;
            btn.SetActive(true);
        }
    }
}
