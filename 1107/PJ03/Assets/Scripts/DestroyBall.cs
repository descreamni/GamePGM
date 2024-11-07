using UnityEngine;

public class DestroyBall : MonoBehaviour
{
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        Destroy(gameObject,5.0f);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
