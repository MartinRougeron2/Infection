using UnityEngine;
using UnityEngine.Events;

public class Health : MonoBehaviour
{
    [Tooltip("Maximum amount of health")]
    public float maxHealth = 1f;
    [Tooltip("Health ratio at which the critical health vignette starts appearing")]
    public float criticalHealthRatio = 0.3f;

    public bool isEagle = false;

    public UnityAction<float, GameObject> onDamaged;
    public UnityAction<float> onHealed;
    public UnityAction onDie;

    public float currentHealth { get; set; }
    public bool invincible { get; set; }
    public bool canPickup() => currentHealth < maxHealth;

    public float getRatio() => currentHealth / maxHealth;
    public bool isCritical() => getRatio() <= criticalHealthRatio;

    bool m_IsDead;

    private void Start()
    {
        currentHealth = maxHealth;
    }

    public void Heal(float healAmount)
    {
        float healthBefore = currentHealth;
        currentHealth += healAmount;
        currentHealth = Mathf.Clamp(currentHealth, 0f, maxHealth);

        // call OnHeal action
        float trueHealAmount = currentHealth - healthBefore;
        if (trueHealAmount > 0f && onHealed != null)
        {
            onHealed.Invoke(trueHealAmount);
        }
    }

    public bool TakeDamage(float damage, GameObject damageSource)
    {
        Health DS = damageSource.GetComponent<Health>();
        if (DS)
            DS.isEagle = false;
        if (invincible || isEagle || !DS.isEagle)
            return false;

        isEagle = true;
        return true;
    }

    public void Kill()
    {
        currentHealth = 0f;

        // call OnDamage action
        if (onDamaged != null)
        {
            onDamaged.Invoke(maxHealth, null);
        }

        HandleDeath();
    }

    private void HandleDeath()
    {
        if (m_IsDead)
            return;

        // call OnDie action
        if (currentHealth <= 0f)
        {
            if (onDie != null)
            {
                m_IsDead = true;
                onDie.Invoke();
            }
        }
    }
}
