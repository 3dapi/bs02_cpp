#include <iostream>
#include <ostream>

class MobBase
{
public:
    virtual ~MobBase() = default;

    virtual void Think()
    {
        std::cout << "Mob Think\n";
    }
};

class ISavable
{
public:
    virtual ~ISavable() = default;
    virtual void Save(std::ostream& output) const = 0;
};

class BossMonster : public MobBase, public ISavable
{
public:
    void Save(std::ostream& output) const override
    {
        output << "BossMonster\n";
    }
};

int main()
{
    BossMonster boss;
    boss.Think();
    boss.Save(std::cout);
}
