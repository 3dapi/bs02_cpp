#include <iostream>

class GameObject
{
public:
    virtual ~GameObject() = default;
};

class BossMonster : public GameObject
{
public:
    void EnterRageMode()
    {
        std::cout << "Boss rage mode\n";
    }
};

int main()
{
    BossMonster original;
    GameObject* object = &original;

    BossMonster* boss = static_cast<BossMonster*>(object);
    boss->EnterRageMode();
}
