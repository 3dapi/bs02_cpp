#include <iostream>
#include <memory>
#include <utility>

class IMobBehavior
{
public:
    virtual ~IMobBehavior() = default;
    virtual void Think() = 0;
};

class PatrolBehavior : public IMobBehavior
{
public:
    void Think() override
    {
        std::cout << "Patrol\n";
    }
};

class ChaseBehavior : public IMobBehavior
{
public:
    void Think() override
    {
        std::cout << "Chase\n";
    }
};

class Monster
{
public:
    explicit Monster(std::unique_ptr<IMobBehavior> behavior)
        : behavior(std::move(behavior))
    {
    }

    void SetBehavior(std::unique_ptr<IMobBehavior> behavior)
    {
        this->behavior = std::move(behavior);
    }

    void Think()
    {
        behavior->Think();
    }

private:
    std::unique_ptr<IMobBehavior> behavior;
};

int main()
{
    Monster monster(std::make_unique<PatrolBehavior>());
    monster.Think();

    monster.SetBehavior(std::make_unique<ChaseBehavior>());
    monster.Think();
}
