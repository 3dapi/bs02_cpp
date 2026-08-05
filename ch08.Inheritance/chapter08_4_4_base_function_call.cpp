#include <iostream>

class GameObject
{
public:
    virtual ~GameObject() = default;

    virtual void Update()
    {
        std::cout << "GameObject Update\n";
    }
};

class Character : public GameObject
{
public:
    void Update() override
    {
        GameObject::Update();
        std::cout << "Character Update\n";
    }
};

class Player : public Character
{
public:
    void Update() override
    {
        Character::Update();
        std::cout << "Player Update\n";
    }
};

int main()
{
    Player player;
    player.Update();
}
