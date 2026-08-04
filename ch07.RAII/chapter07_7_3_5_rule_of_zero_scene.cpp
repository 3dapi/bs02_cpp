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

    void Print() const
    {
        std::cout << "Enemy " << id << '\n';
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

    void Print() const
    {
        for (const auto& enemy : enemies)
        {
            enemy->Print();
        }
    }

private:
    std::vector<std::unique_ptr<Enemy>> enemies;
};

int main()
{
    GameScene scene;

    scene.AddEnemy(std::make_unique<Enemy>(1));
    scene.AddEnemy(std::make_unique<Enemy>(2));

    scene.Print();
}
