#include <iostream>

class IRenderable
{
public:
    virtual ~IRenderable() = default;

    virtual void Reset()
    {
        std::cout << "IRenderable Reset\n";
    }
};

class ISavable
{
public:
    virtual ~ISavable() = default;

    virtual void Reset()
    {
        std::cout << "ISavable Reset\n";
    }
};

class BossMonster : public IRenderable, public ISavable
{
public:
    void Reset() override
    {
        IRenderable::Reset();
        ISavable::Reset();
        std::cout << "BossMonster Reset\n";
    }
};

int main()
{
    BossMonster boss;
    boss.Reset();
}
