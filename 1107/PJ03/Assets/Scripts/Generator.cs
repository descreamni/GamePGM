using UnityEngine;

public class Cannon : MonoBehaviour
{
    public GameObject prefab;
    public float pow;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            GameObject bullet = LoadBullet();
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            Vector3 dir = ray.direction.normalized;

            bullet.GetComponent<Rigidbody>().linearVelocity = dir * pow;
        }
    }
    GameObject LoadBullet()
    {
        GameObject bullet = GameObject.Instantiate(prefab) as GameObject;

        bullet.transform.parent = transform;
        bullet.transform.localPosition = Vector3.zero;

        return bullet;

    }
}
