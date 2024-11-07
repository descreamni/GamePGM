using UnityEngine;

public class QueryChanController : MonoBehaviour
{
    public float spd = 3.0f;
    public float jmpPow = 6.0f;
    private Vector3 direction;
    private CharacterController controller;
    private Animator anim;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        controller = GetComponent<CharacterController>();
        anim = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        float inputX = Input.GetAxis("Vertical");
        float inputY = Input.GetAxis("Horizontal");
        Vector3 inputDirection = new Vector3(-inputY, 0, -inputX);
        direction = Vector3.zero;
        if(inputDirection.magnitude>0.1f)
        {
            transform.LookAt(transform.position + inputDirection);
            direction += transform.forward * spd;
            anim.SetFloat("Speed", direction.magnitude);
        }
        else
        {
            anim.SetFloat("Speed", 0);
        }

        if(Input.GetButton("Jump"))
        {
            anim.SetTrigger("Jump");
            direction.y += jmpPow;
        }
        controller.Move(direction * Time.deltaTime);
        direction.y += Physics.gravity.y * Time.deltaTime;
    }
}
