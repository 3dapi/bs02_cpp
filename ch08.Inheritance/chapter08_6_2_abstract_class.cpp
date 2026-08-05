#include <iostream>

class GameObject
{
public:
    virtual ~GameObject() = default;
    virtual void Update() = 0;
};

class Character : public GameObject
{
public:
    explicit Character(int hp)
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

class Monster : public Character
{
public:
    explicit Monster(int hp)
        : Character(hp)
    {
    }

    void Update() override
    {
        std::cout << "Monster hp=" << GetHp() << '\n';
    }
};

int main()
{
    Monster monster(80);
    GameObject& object = monster;
    object.Update();
}
