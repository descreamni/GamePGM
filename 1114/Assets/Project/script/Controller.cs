using Unity.VisualScripting;
using UnityEngine;

public class Controller : MonoBehaviour
{
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    public GameObject MainCamera;
    public float mouseSensitivity = 100f;
    private Rigidbody rig;
    public float JumpForce = 5f;
    public Vector2 SpeedGraph = new Vector2(5f, 5f);
    private bool bIsGrounded;

    private float fXRot = 0f;
    private float vertOffset = 0f;
    
    void Start()
    {
        rig = GetComponent<Rigidbody>();
        Cursor.lockState = CursorLockMode.Locked;

    }

    // Update is called once per frame
    void Update()
    {
        

        rig.linearVelocity = new Vector3(-Input.GetAxis("Vertical")*SpeedGraph.x,rig.linearVelocity.y, Input.GetAxis("Horizontal")* SpeedGraph.y);
        if (Input.GetKeyDown("space") && bIsGrounded)
        {
            Jump();
        }
        MouseMove();
    }
    void Jump()
    {
        Debug.Log("µé¾î¿È");
        rig.linearVelocity = new Vector3(rig.linearVelocity.x, JumpForce, rig.linearVelocity.z);
        bIsGrounded = false;
    }
    void MouseMove()
    {
        float mouseX = -Input.GetAxis("MouseAxisX") * mouseSensitivity * Time.deltaTime;
        float mouseY = Input.GetAxis("MouseAxisY") * mouseSensitivity * Time.deltaTime;

        fXRot -= mouseY;
        fXRot = Mathf.Clamp(fXRot, -90f, 90f);
        MainCamera.transform.localRotation = Quaternion.Euler(fXRot, 0f, 0f);

        transform.Rotate(Vector3.up * mouseX);
    }
    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.CompareTag("Ground"))
        {
            Debug.Log("ÂøÁö");
            bIsGrounded = true;
        }
    }
}
