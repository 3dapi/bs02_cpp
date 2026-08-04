#include <iostream>

class GameObject
{
public:
    virtual ~GameObject()
    {
        std::cout << "GameObject 소멸\n";
    }
};

class Character : public GameObject
{
public:
    ~Character() override
    {
        std::cout << "Character 소멸\n";
    }
};

class BossMonster : public Character
{
public:
    ~BossMonster() override
    {
        std::cout << "BossMonster 소멸\n";
    }
};

int main()
{
    GameObject* object = new BossMonster;
    delete object;
}
