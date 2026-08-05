#include <algorithm>
#include <iostream>

class IUpdatable
{
public:
    virtual ~IUpdatable() = default;
    virtual void Update() = 0;
};

class IRenderable
{
public:
    virtual ~IRenderable() = default;
    virtual void Render() const = 0;
};

class IDamageable
{
public:
    virtual ~IDamageable() = default;
    virtual int TakeDamage(int damage) = 0;
};

class Player : public IUpdatable,
               public IRenderable,
               public IDamageable
{
public:
    void Update() override
    {
        std::cout << "player update\n";
    }

    void Render() const override
    {
        std::cout << "player render\n";
    }

    int TakeDamage(int damage) override
    {
        const int oldHp = hp;
        hp = std::max(hp - std::max(damage, 0), 0);
        return oldHp - hp;
    }

private:
    int hp = 100;
};

class ParticleEffect : public IUpdatable,
                       public IRenderable
{
public:
    void Update() override
    {
        std::cout << "particle update\n";
    }

    void Render() const override
    {
        std::cout << "particle render\n";
    }
};

void UpdateObject(IUpdatable& object)
{
    object.Update();
}

void RenderObject(const IRenderable& object)
{
    object.Render();
}

int main()
{
    Player player;
    ParticleEffect particle;

    UpdateObject(player);
    RenderObject(player);
    UpdateObject(particle);
    RenderObject(particle);
}
