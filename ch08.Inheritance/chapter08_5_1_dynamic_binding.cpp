#include <iostream>

class GameObject
{
public:
    virtual ~GameObject() = default;

    virtual void PrintType() const
    {
        std::cout << "GameObject\n";
    }
};

class Player : public GameObject
{
public:
    void PrintType() const override
    {
        std::cout << "Player\n";
    }
};

int main()
{
    Player player;
    GameObject& object = player;

    object.PrintType();
}
