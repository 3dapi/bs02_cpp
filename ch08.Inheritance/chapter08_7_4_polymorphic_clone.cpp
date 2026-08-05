#include <iostream>
#include <memory>

class GameObject
{
public:
    virtual ~GameObject() = default;
    virtual std::unique_ptr<GameObject> Clone() const = 0;
    virtual const char* TypeName() const = 0;
};

class BossMonster : public GameObject
{
public:
    explicit BossMonster(int phase)
        : phase(phase)
    {
    }

    std::unique_ptr<GameObject> Clone() const override
    {
        return std::make_unique<BossMonster>(*this);
    }

    const char* TypeName() const override
    {
        return "BossMonster";
    }

    int GetPhase() const
    {
        return phase;
    }

private:
    int phase;
};

int main()
{
    std::unique_ptr<GameObject> original =
        std::make_unique<BossMonster>(2);
    std::unique_ptr<GameObject> copy = original->Clone();

    std::cout << original->TypeName() << '\n';
    std::cout << copy->TypeName() << '\n';
}
