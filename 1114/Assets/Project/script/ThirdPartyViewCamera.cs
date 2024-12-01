using System.Runtime.CompilerServices;
using UnityEngine;

public class ThirdPartyViewCamera: MonoBehaviour
{
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    public GameObject CameraSocket;
    public GameObject Focus;
    private Vector2 MousePosition;
    public float MouseSensitivity = 100f;
    private float fXRot = 0;

    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        Position();
        Rotation();
        
    }
    private void Rotation()
    {
        CameraSocket.transform.LookAt(Focus.transform);
    }
    private void Position()
    {
        CameraSocket.transform.position = transform.position;
    }
}
