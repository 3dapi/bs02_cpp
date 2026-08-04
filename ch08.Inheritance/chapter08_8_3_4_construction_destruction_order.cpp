#include <iostream>

class GameObject
{
public:
    GameObject()
    {
        std::cout << "GameObject 생성\n";
    }

    virtual ~GameObject()
    {
        std::cout << "GameObject 소멸\n";
    }
};

class Character : public GameObject
{
public:
    Character()
    {
        std::cout << "Character 생성\n";
    }

    ~Character() override
    {
        std::cout << "Character 소멸\n";
    }
};

class BossMonster : public Character
{
public:
    BossMonster()
    {
        std::cout << "BossMonster 생성\n";
    }

    ~BossMonster() override
    {
        std::cout << "BossMonster 소멸\n";
    }
};

int main()
{
    BossMonster boss;
}
