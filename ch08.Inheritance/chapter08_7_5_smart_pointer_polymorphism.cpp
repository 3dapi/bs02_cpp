#include <iostream>
#include <memory>
#include <vector>

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
        std::cout << "Player Update\n";
    }
};

class Monster : public GameObject
{
public:
    void Update() override
    {
        std::cout << "Monster Update\n";
    }
};

int main()
{
    std::vector<std::unique_ptr<GameObject>> objects;
    objects.push_back(std::make_unique<Player>());
    objects.push_back(std::make_unique<Monster>());

    for (const auto& object : objects)
    {
        object->Update();
    }
}
