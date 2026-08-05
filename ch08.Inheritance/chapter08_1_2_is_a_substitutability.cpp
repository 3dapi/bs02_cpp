#include <iostream>

class Character
{
public:
    virtual ~Character() = default;

    virtual const char* TypeName() const
    {
        return "Character";
    }

    int GetHp() const
    {
        return hp;
    }

protected:
    int hp = 100;
};

class Player : public Character
{
public:
    const char* TypeName() const override
    {
        return "Player";
    }
};

class Monster : public Character
{
public:
    const char* TypeName() const override
    {
        return "Monster";
    }
};

void PrintCharacterState(const Character& character)
{
    std::cout << character.TypeName()
              << ": hp=" << character.GetHp() << '\n';
}

int main()
{
    Player player;
    Monster monster;

    PrintCharacterState(player);
    PrintCharacterState(monster);
}
