#include <iostream>
#include <memory>

class Enemy
{
public:
    explicit Enemy(int hp)
        : hp(hp)
    {
    }

    int Hp() const
    {
        return hp;
    }

    void TakeDamage(int damage)
    {
        hp -= damage;
    }

private:
    int hp;
};

void DrawEnemy(const Enemy& enemy)
{
    std::cout << enemy.Hp() << '\n';
}

void UpdateEnemy(Enemy& enemy)
{
    enemy.TakeDamage(10);
}

void ObserveEnemy(const Enemy* enemy)
{
    if (enemy != nullptr)
    {
        DrawEnemy(*enemy);
    }
}

int main()
{
    auto enemy = std::make_unique<Enemy>(100);

    DrawEnemy(*enemy);
    UpdateEnemy(*enemy);
    ObserveEnemy(enemy.get());
}
