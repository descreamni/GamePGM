using Unity.VisualScripting;
using UnityEngine;

public class CamMov : MonoBehaviour
{
    public GameObject Target;
    private Transform transf;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        transf = Target.GetComponent<Transform>();
    }

    // Update is called once per frame
    void Update()
    {
        
        if (transf != null)
        {
            transform.rotation = Quaternion.Euler(25 - Input.mousePosition.y * 0.1f, 180 + Input.mousePosition.x*0.1f, 0);
            this.transform.position = new Vector3(transf.position.x,transf.position.y,transf.position.z );
            
        }

    }
}
