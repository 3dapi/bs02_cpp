#include <iostream>

class GameObject
{
public:
    explicit GameObject(int id)
        : id(id)
    {
    }

    int GetId() const
    {
        return id;
    }

private:
    int id;
};

class Character : public GameObject
{
public:
    Character()
        : GameObject(10)
    {
    }
};

class NetworkObject : public GameObject
{
public:
    NetworkObject()
        : GameObject(20)
    {
    }
};

class NetworkCharacter : public Character, public NetworkObject
{
};

int main()
{
    NetworkCharacter object;

    std::cout << object.Character::GetId() << '\n';
    std::cout << object.NetworkObject::GetId() << '\n';
}
