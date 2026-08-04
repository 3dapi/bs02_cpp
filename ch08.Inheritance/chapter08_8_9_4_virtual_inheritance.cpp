#include <iostream>

class GameObject
{
public:
    GameObject() = default;

    int GetId() const
    {
        return id;
    }

protected:
    int id = 100;
};

class Character : public virtual GameObject
{
};

class NetworkObject : public virtual GameObject
{
};

class NetworkCharacter : public Character, public NetworkObject
{
};

int main()
{
    NetworkCharacter object;
    std::cout << object.GetId() << '\n';
}
