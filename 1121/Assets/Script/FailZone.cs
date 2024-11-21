using UnityEngine;
using UnityEngine.SceneManagement;
public class FailZone : MonoBehaviour
{
    void OnTriggerEnter(Collider collider)
    {
        
        if (collider.gameObject.name == "Ball")
        {
            //GameObject.Find("GameManager").SendMessage("RestartGame");
            GameObject gm = GameObject.Find("GameManager");
            GameManager gmComponent = gm.GetComponent<GameManager>();
            gmComponent.RestartGame();

        }
    }

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
