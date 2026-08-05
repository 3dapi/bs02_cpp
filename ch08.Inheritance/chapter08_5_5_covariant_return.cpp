#include <iostream>

class GameObject
{
public:
    virtual ~GameObject() = default;

    virtual GameObject* Self()
    {
        return this;
    }

    virtual const char* TypeName() const
    {
        return "GameObject";
    }
};

class Player : public GameObject
{
public:
    Player* Self() override
    {
        return this;
    }

    const char* TypeName() const override
    {
        return "Player";
    }
};

int main()
{
    Player player;
    GameObject& object = player;
    GameObject* self = object.Self();

    std::cout << self->TypeName() << '\n';
}
