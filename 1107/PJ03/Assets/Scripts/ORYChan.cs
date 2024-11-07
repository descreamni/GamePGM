using UnityEngine;

public class ORYChan : MonoBehaviour
{
    public float pow = 6.5f;
    private GameObject target;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        target = GameObject.FindGameObjectWithTag("DeathZone");
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        Vector3 direction = target.transform.position - transform.position;
        GetComponent<Rigidbody>().AddForce(direction.normalized * pow);
        transform.LookAt(direction);
    }
}
