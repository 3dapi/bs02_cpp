#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

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

class Character : public GameObject
{
public:
    Character(int id, std::string name, int maxHp)
        : GameObject(id, std::move(name)),
          hp(std::max(maxHp, 0))
    {
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp;
};

class PlayerBase : public Character
{
public:
    PlayerBase(int id, std::string name, int maxHp)
        : Character(id, std::move(name), maxHp)
    {
    }

    virtual void ProcessInput() = 0;
};

class Player : public PlayerBase
{
public:
    Player(int id, std::string name, int maxHp)
        : PlayerBase(id, std::move(name), maxHp)
    {
    }

    void ProcessInput() override
    {
        std::cout << GetName() << " input\n";
    }

    void Update() override
    {
        ProcessInput();
        std::cout << "hp=" << GetHp() << '\n';
    }
};

int main()
{
    Player player(1, "Knight", 150);
    player.Update();
}
