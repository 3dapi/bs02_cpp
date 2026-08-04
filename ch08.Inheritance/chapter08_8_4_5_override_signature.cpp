#include <iostream>

class MobBase
{
public:
    virtual ~MobBase() = default;

    virtual void Think() const
    {
        std::cout << "MobBase Think\n";
    }
};

class Monster : public MobBase
{
public:
    void Think() const override
    {
        std::cout << "Monster patrol\n";
    }
};

int main()
{
    Monster monster;
    const MobBase& mob = monster;
    mob.Think();
}
