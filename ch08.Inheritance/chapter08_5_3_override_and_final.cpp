#include <iostream>

class MobBase
{
public:
    virtual ~MobBase() = default;

    virtual void EnterRageMode()
    {
        std::cout << "Mob rage mode\n";
    }
};

class BossMonster : public MobBase
{
public:
    void EnterRageMode() final
    {
        std::cout << "Boss rage mode\n";
    }
};

class FinalBossMonster final : public BossMonster
{
};

int main()
{
    FinalBossMonster boss;
    MobBase& mob = boss;
    mob.EnterRageMode();
}
