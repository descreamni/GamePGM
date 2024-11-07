using UnityEngine;

public class HiyokoCreator : MonoBehaviour
{
    public GameObject obj;
    public float interval = 3.0f;
    private float time;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(DeathZone.dead == false)
        {
            time += Time.deltaTime;
            if (time >= interval)
            {
                time = 0;
                GameObject hiyoko = Instantiate(obj) as GameObject;
                hiyoko.transform.localPosition = new Vector3(
                    Random.Range(-3.0f, -3.0f), 
                    Random.Range(1.0f, 1.0f), 
                    Random.Range(17.0f, 20.0f));
                Score.score++;
            }
        }
      
    }
}
