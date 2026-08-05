#include <iostream>
#include <memory>

class Enemy
{
public:
    Enemy(int hp, int attack)
        : hp(hp), attack(attack)
    {
    }

    void Print() const
    {
        std::cout << hp << ' '
                  << attack << '\n';
    }

private:
    int hp;
    int attack;
};

std::unique_ptr<Enemy> CreateEnemy(
    int hp,
    int attack
)
{
    return std::make_unique<Enemy>(
        hp,
        attack
    );
}

int main()
{
    auto enemy = CreateEnemy(100, 20);

    enemy->Print();
}
