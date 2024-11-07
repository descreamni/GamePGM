using UnityEngine;

public class DeathZone : MonoBehaviour
{
    public static bool dead;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        dead = false;
    }

    // Update is called once per frame
    private void OnTriggerEnter(Collider col)
    {
        if (col.gameObject.tag == "ORYChan")
        {
            UIController.gameOver = true;
            dead = true;
        }
    }
}
