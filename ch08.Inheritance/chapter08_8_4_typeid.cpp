#include <iostream>
#include <typeinfo>

class GameObject
{
public:
    virtual ~GameObject() = default;
};

class BossMonster : public GameObject
{
};

int main()
{
    BossMonster boss;
    GameObject& object = boss;

    if (typeid(object) == typeid(BossMonster))
    {
        std::cout << "BossMonster object\n";
    }

    std::cout << typeid(object).name() << '\n';
}
