#include <iostream>

class GameObject
{
public:
    virtual ~GameObject() = default;

    virtual const char* TypeName() const
    {
        return "GameObject";
    }
};

class Character : public GameObject
{
};

class Player : public Character
{
public:
    const char* TypeName() const override
    {
        return "Player";
    }
};

int main()
{
    Player player;

    Character* character = &player;
    GameObject* object = character;

    std::cout << object->TypeName() << '\n';
}
