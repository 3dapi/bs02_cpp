#include <iostream>

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
public:
    void EnterRageMode()
    {
        std::cout << "Boss rage mode\n";
    }
};

void ActivateBossMode(GameObject* object)
{
    BossMonster* boss = dynamic_cast<BossMonster*>(object);

    if (boss != nullptr)
    {
        boss->EnterRageMode();
    }
    else
    {
        std::cout << "BossMonster가 아님\n";
    }
}

int main()
{
    Player player;
    BossMonster boss;

    ActivateBossMode(&player);
    ActivateBossMode(&boss);
}
