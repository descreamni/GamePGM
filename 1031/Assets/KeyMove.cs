using UnityEngine;

public class KeyMove : MonoBehaviour
{
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.rotation *= Quaternion.AngleAxis(Input.GetAxis("Horizontal") * 30.0f * Time.deltaTime, new Vector3(0, 0, 1));
        transform.rotation *= Quaternion.AngleAxis(Input.GetAxis("Vertical") * 30.0f * Time.deltaTime, new Vector3(1, 0, 0));
    }
}
