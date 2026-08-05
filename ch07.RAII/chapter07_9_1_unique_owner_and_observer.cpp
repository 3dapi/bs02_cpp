#include <iostream>
#include <memory>
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
    Enemy& AddEnemy(int id)
    {
        auto enemy = std::make_unique<Enemy>(id);
        Enemy& reference = *enemy;

        enemies.push_back(std::move(enemy));

        return reference;
    }

private:
    std::vector<std::unique_ptr<Enemy>> enemies;
};

class EnemySystem
{
public:
    explicit EnemySystem(GameScene& scene)
        : scene(scene)
    {
    }

    void Update() const
    {
        std::cout << "EnemySystem 갱신\n";
    }

private:
    GameScene& scene;
};

int main()
{
    GameScene scene;
    EnemySystem system(scene);

    Enemy& enemy = scene.AddEnemy(1);

    system.Update();

    std::cout << enemy.Id() << '\n';
}
