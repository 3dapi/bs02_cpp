#include <iostream>

class Character
{
public:
    int GetHp() const
    {
        return hp;
    }

protected:
    void SetHp(int hp)
    {
        this->hp = hp < 0 ? 0 : hp;
    }

private:
    int hp = 100;
};

class BossMonster : public Character
{
public:
    void Recover(int amount)
    {
        if (amount > 0)
        {
            SetHp(GetHp() + amount);
        }
    }
};

int main()
{
    BossMonster boss;
    boss.Recover(50);
    std::cout << boss.GetHp() << '\n';
}
