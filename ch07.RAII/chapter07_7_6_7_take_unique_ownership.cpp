#include <iostream>
#include <memory>
#include <utility>
#include <vector>

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

class GameScene
{
public:
    void AddEnemy(std::unique_ptr<Enemy> enemy)
    {
        enemies.push_back(std::move(enemy));
    }

    std::size_t EnemyCount() const
    {
        return enemies.size();
    }

private:
    std::vector<std::unique_ptr<Enemy>> enemies;
};

int main()
{
    GameScene scene;
    auto enemy = std::make_unique<Enemy>(1);

    scene.AddEnemy(std::move(enemy));

    std::cout << std::boolalpha;
    std::cout << (enemy == nullptr) << '\n';
    std::cout << scene.EnemyCount() << '\n';
}
