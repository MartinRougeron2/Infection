using UnityEngine;

public class Damageable : MonoBehaviour
{
    [Tooltip("Multiplier to apply to the received damage")]
    public float damageMultiplier = 1f;
    [Range(0, 1)]
    [Tooltip("Multiplier to apply to self damage")]
    public float sensibilityToSelfdamage = 0.5f;

    public Health health { get; private set; }

    void Awake()
    {
        // find the health component either at the same level, or higher in the hierarchy
        health = GetComponent<Health>();
        if (!health)
        {
            health = GetComponentInParent<Health>();
        }
    }

    public bool InflictDamage(float damage, bool isExplosionDamage, GameObject damageSource)
    {

        if(health)
        {
            return (health.TakeDamage(0, damageSource));
        }
        return false;
    }
}
