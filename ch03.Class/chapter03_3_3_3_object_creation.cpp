#include <iostream>

class Character
{
public:
    void TakeDamage(int damage)
    {
        if (hp -= damage; hp < 0)
        {
            hp = 0;
        }
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp = 100;
};

int main()
{
    Character player;
    Character enemy;

    player.TakeDamage(20);
    enemy.TakeDamage(60);

    std::cout << "Player: " << player.GetHp() << '\n';
    std::cout << "Enemy: " << enemy.GetHp() << '\n';
}
