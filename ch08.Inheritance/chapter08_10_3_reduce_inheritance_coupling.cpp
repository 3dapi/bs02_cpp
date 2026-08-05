#include <iostream>

class Character
{
public:
    int GetHp() const
    {
        return hp;
    }

protected:
    void Recover(int amount)
    {
        if (amount > 0)
        {
            hp += amount;
        }
    }

private:
    int hp = 100;
};

class MobBase : public Character
{
public:
    void RecoverHalfHp()
    {
        Recover(50);
    }
};

int main()
{
    MobBase mob;
    mob.RecoverHalfHp();
    std::cout << mob.GetHp() << '\n';
}
