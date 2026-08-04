#include <iostream>
#include <memory>

class Enemy
{
public:
    explicit Enemy(int id)
        : id(id)
    {
    }

    void Print() const
    {
        std::cout << "Enemy " << id << '\n';
    }

private:
    int id;
};

void UseEnemy(const Enemy* enemy)
{
    if (enemy != nullptr)
    {
        enemy->Print();
    }
}

int main()
{
    auto enemy = std::make_unique<Enemy>(1);

    Enemy* observed = enemy.get();
    UseEnemy(observed);

    enemy.reset(new Enemy(2));
    UseEnemy(enemy.get());

    Enemy* owned = enemy.release();
    UseEnemy(owned);

    delete owned;
}
