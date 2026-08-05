#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

class GameSystem
{
public:
    static void BeginFrame(float deltaTime)
    {
        GameSystem::deltaTime = std::max(deltaTime, 0.0f);
    }

    static float GetDeltaTime()
    {
        return deltaTime;
    }

private:
    inline static float deltaTime = 0.0f;
};

class HealthComponent
{
public:
    explicit HealthComponent(int maxHp)
        : hp(std::max(maxHp, 0)),
          maxHp(std::max(maxHp, 0))
    {
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp;
    int maxHp;
};

class GameObject
{
public:
    GameObject(int id, std::string name)
        : id(id), name(std::move(name))
    {
    }

    virtual ~GameObject() = default;
    virtual void Update() = 0;

    const std::string& GetName() const
    {
        return name;
    }

private:
    int id;
    std::string name;
};

class SampleObject : public GameObject
{
public:
    SampleObject()
        : GameObject(1, "Sample"), health(100)
    {
    }

    void Update() override
    {
        std::cout << GetName() << ": "
                  << GameSystem::GetDeltaTime()
                  << ", hp=" << health.GetHp() << '\n';
    }

private:
    HealthComponent health;
};

int main()
{
    GameSystem::BeginFrame(0.016f);
    SampleObject object;
    object.Update();
}
