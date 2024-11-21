using UnityEngine;

public class PrtPosition : MonoBehaviour
{
    float startingPoint;
    private bool isOver20 = true;
    private bool isOver40 = true;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        Debug.Log("Start");
        startingPoint = transform.position.z;
    }

    // Update is called once per frame
    void Update()
    {
        float distance;
        distance = transform.position.z - startingPoint;

        if(distance > 40)
        {
            if (isOver40)
            {
                Debug.Log("Over 40: " + distance);
                isOver40 = false;
            }
        }
        else if (distance > 20)
        {
            if (isOver20)
            {
                Debug.Log("Over 20: " + distance);
                isOver20 = false;
            }
          
        }

    }
}
