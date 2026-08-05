#include <iostream>
#include <ostream>

class Character
{
public:
    virtual ~Character() = default;

    int GetHp() const
    {
        return hp;
    }

protected:
    int hp = 100;
};

class ISavable
{
public:
    virtual ~ISavable() = default;
    virtual void Save(std::ostream& output) const = 0;
};

class BossMonster : public Character, public ISavable
{
public:
    void Save(std::ostream& output) const override
    {
        output << "BossMonster hp=" << GetHp() << '\n';
    }
};

int main()
{
    BossMonster boss;
    const ISavable& savable = boss;
    savable.Save(std::cout);
}
