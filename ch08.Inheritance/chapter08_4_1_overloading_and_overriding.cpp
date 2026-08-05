#include <iostream>

class Character
{
public:
    virtual ~Character() = default;

    void Move(float distance)
    {
        std::cout << "Move distance " << distance << '\n';
    }

    void Move(float x, float y)
    {
        std::cout << "Move to " << x << ", " << y << '\n';
    }

    virtual void Update()
    {
        std::cout << "Character Update\n";
    }
};

class Monster : public Character
{
public:
    void Update() override
    {
        std::cout << "Monster Update\n";
    }
};

int main()
{
    Monster monster;
    monster.Move(5.0f);
    monster.Move(10.0f, 20.0f);

    Character& character = monster;
    character.Update();
}
