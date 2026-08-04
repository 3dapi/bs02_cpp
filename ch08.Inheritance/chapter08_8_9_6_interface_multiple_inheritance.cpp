#include <iostream>
#include <ostream>

class ISavable
{
public:
    virtual ~ISavable() = default;
    virtual void Save(std::ostream& output) const = 0;
};

class ITargetable
{
public:
    virtual ~ITargetable() = default;
    virtual bool CanBeTargeted() const = 0;
};

class BossMonster : public ISavable, public ITargetable
{
public:
    void Save(std::ostream& output) const override
    {
        output << "BossMonster\n";
    }

    bool CanBeTargeted() const override
    {
        return true;
    }
};

int main()
{
    BossMonster boss;
    const ISavable& savable = boss;
    const ITargetable& targetable = boss;

    savable.Save(std::cout);
    std::cout << std::boolalpha
              << targetable.CanBeTargeted() << '\n';
}
