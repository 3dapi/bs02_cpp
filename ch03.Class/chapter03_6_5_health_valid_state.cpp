#include <iostream>

class Health
{
public:
    void TakeDamage(int damage)
    {
        if (damage <= 0)
        {
            return;
        }

        current -= damage;

        if (current < 0)
        {
            current = 0;
        }
    }

    void Recover(int amount)
    {
        if (amount <= 0)
        {
            return;
        }

        current += amount;

        if (current > maximum)
        {
            current = maximum;
        }
    }

    int GetCurrent() const
    {
        return current;
    }

    int GetMaximum() const
    {
        return maximum;
    }

private:
    int current = 100;
    int maximum = 100;
};

int main()
{
    Health health;

    health.TakeDamage(30);
    health.Recover(10);

    std::cout << health.GetCurrent() << '\n';
}
