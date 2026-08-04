#include <iostream>

class HealthComponent
{
public:
    explicit HealthComponent(int hp)
        : hp(hp)
    {
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp;
};

class GameObject
{
public:
    virtual ~GameObject() = default;
    virtual void Render() const = 0;
};

class Character : public GameObject
{
public:
    explicit Character(int hp)
        : health(hp)
    {
    }

    int GetHp() const
    {
        return health.GetHp();
    }

private:
    HealthComponent health;
};

class Monster : public Character
{
public:
    explicit Monster(int hp)
        : Character(hp)
    {
    }

    void Render() const override
    {
        std::cout << "Monster hp=" << GetHp() << '\n';
    }
};

int main()
{
    Monster monster(80);
    GameObject& object = monster;
    object.Render();
}
