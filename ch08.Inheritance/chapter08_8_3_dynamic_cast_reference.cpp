#include <iostream>
#include <typeinfo>

class GameObject
{
public:
    virtual ~GameObject() = default;
};

class Player : public GameObject
{
};

class BossMonster : public GameObject
{
};

int main()
{
    Player player;
    GameObject& object = player;

    try
    {
        [[maybe_unused]] BossMonster& boss =
            dynamic_cast<BossMonster&>(object);
    }
    catch (const std::bad_cast& error)
    {
        std::cout << error.what() << '\n';
    }
}
