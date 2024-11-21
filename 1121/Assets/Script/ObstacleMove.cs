using UnityEngine;

public class ObstacleMove : MonoBehaviour
{
    void OnColisionEnter(Collision collision)
    {
        Vector3 direction = transform.position - collision.gameObject.transform.position;
        direction = direction.normalized * 1000;
        collision.gameObject.GetComponent<Rigidbody>().AddForce(direction);
    }
    float delta = 0.01f;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    public void Update()
    {
        float newXPosition = transform.localPosition.x + delta;
        transform.localPosition = new Vector3(newXPosition,
        transform.localPosition.y,
        transform.localPosition.z);
        if (transform.localPosition.x < -9)
        {
            delta = 0.01f;
        }
        else if (transform.localPosition.x > 9)
        {
            delta = -0.01f;
        }
    }
    void TestMethod(string name, int a)
    {
        float distance = Vector3.Distance(GameObject.Find(name).transform.position, transform.position);
        Debug.Log(name + "까지 거리" + distance);
    }

}
