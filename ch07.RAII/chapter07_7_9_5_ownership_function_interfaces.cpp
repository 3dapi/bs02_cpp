#include <iostream>
#include <memory>
#include <utility>

class Enemy
{
public:
    explicit Enemy(int id)
        : id(id)
    {
    }

    int Id() const
    {
        return id;
    }

private:
    int id;
};

std::unique_ptr<Enemy> CreateEnemy()
{
    return std::make_unique<Enemy>(1);
}

void ReadEnemy(const Enemy& enemy)
{
    std::cout << enemy.Id() << '\n';
}

void TakeEnemy(std::unique_ptr<Enemy> enemy)
{
    ReadEnemy(*enemy);
}

int main()
{
    auto enemy = CreateEnemy();

    ReadEnemy(*enemy);
    TakeEnemy(std::move(enemy));

    std::cout << std::boolalpha;
    std::cout << (enemy == nullptr) << '\n';
}
