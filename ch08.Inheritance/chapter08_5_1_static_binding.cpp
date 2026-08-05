#include <iostream>

class GameObject
{
public:
    void PrintType() const
    {
        std::cout << "GameObject\n";
    }
};

class Player : public GameObject
{
public:
    void PrintType() const
    {
        std::cout << "Player\n";
    }
};

int main()
{
    Player player;
    GameObject& object = player;

    player.PrintType();
    object.PrintType();
}
