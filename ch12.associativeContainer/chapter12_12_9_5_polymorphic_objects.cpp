#include <iostream>
#include <map>
#include <memory>

class GameObject
{
public:
    virtual ~GameObject() = default;
    virtual void Update() = 0;
};

class Player : public GameObject
{
public:
    void Update() override
    {
        std::cout << "Player update\n";
    }
};

class Monster : public GameObject
{
public:
    void Update() override
    {
        std::cout << "Monster update\n";
    }
};

int main()
{
    std::map<int, std::unique_ptr<GameObject>> objects;

    objects.try_emplace(1, std::make_unique<Player>());
    objects.try_emplace(2, std::make_unique<Monster>());

    for (auto& [id, object] : objects)
    {
        std::cout << id << ' ';
        object->Update();
    }
}
