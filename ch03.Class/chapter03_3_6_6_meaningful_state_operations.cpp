#include <iostream>

class Player
{
public:
    void TakeDamage(int damage)
    {
        if (damage <= 0)
        {
            return;
        }

        hp -= damage;

        if (hp < 0)
        {
            hp = 0;
        }
    }

    void Recover(int amount)
    {
        if (amount <= 0)
        {
            return;
        }

        hp += amount;

        if (hp > maxHp)
        {
            hp = maxHp;
        }
    }

    int GetHp() const
    {
        return hp;
    }

    bool IsDead() const
    {
        return hp == 0;
    }

private:
    int hp = 100;
    int maxHp = 100;
};

int main()
{
    Player player;

    player.TakeDamage(120);

    std::cout << player.GetHp() << '\n';
    std::cout << std::boolalpha << player.IsDead() << '\n';
}
