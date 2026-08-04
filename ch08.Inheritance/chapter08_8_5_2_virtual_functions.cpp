#include <iostream>
#include <vector>

class GameObject
{
public:
    virtual ~GameObject() = default;
    virtual void Update() = 0;
    virtual void Render() const = 0;
};

class Player : public GameObject
{
public:
    void Update() override
    {
        std::cout << "Player Update\n";
    }

    void Render() const override
    {
        std::cout << "Player Render\n";
    }
};

class Monster : public GameObject
{
public:
    void Update() override
    {
        std::cout << "Monster Update\n";
    }

    void Render() const override
    {
        std::cout << "Monster Render\n";
    }
};

int main()
{
    Player player;
    Monster monster;
    std::vector<GameObject*> objects{&player, &monster};

    for (GameObject* object : objects)
    {
        object->Update();
        object->Render();
    }
}
