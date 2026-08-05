#include <iostream>

class Character
{
public:
    virtual ~Character() = default;

    virtual void PrintType() const
    {
        std::cout << "Character\n";
    }
};

class Player : public Character
{
public:
    void PrintType() const override
    {
        std::cout << "Player\n";
    }

private:
    int score = 1000;
};

void PrintByValue(Character character)
{
    character.PrintType();
}

void PrintByReference(const Character& character)
{
    character.PrintType();
}

int main()
{
    Player player;

    PrintByValue(player);
    PrintByReference(player);
}
