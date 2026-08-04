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

class Character : public virtual GameObject
{
public:
    Character()
        : GameObject(10)
    {
    }
};

class NetworkObject : public virtual GameObject
{
public:
    NetworkObject()
        : GameObject(20)
    {
    }
};

class NetworkCharacter : public Character, public NetworkObject
{
public:
    NetworkCharacter()
        : GameObject(100), Character(), NetworkObject()
    {
    }
};

int main()
{
    NetworkCharacter object;
    std::cout << object.GetId() << '\n';
}
