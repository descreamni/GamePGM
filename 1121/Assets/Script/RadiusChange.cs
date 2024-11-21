using UnityEngine;

public class RadiusChange : MonoBehaviour
{
    SphereCollider myCollider = new SphereCollider();
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        Rigidbody myRigidbody = GetComponent<Rigidbody>();
        Debug.Log("UseGravity: " + myRigidbody.useGravity);
        myCollider = GetComponent<SphereCollider>();
    }

    // Update is called once per frame
    void Update()
    {
        myCollider.radius = myCollider.radius + 0.01f;
    }
}
