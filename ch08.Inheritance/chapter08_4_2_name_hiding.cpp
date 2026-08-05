#include <iostream>

class Character
{
public:
    void Move(float x, float y)
    {
        std::cout << "Character Move "
                  << x << ", " << y << '\n';
    }
};

class Player : public Character
{
public:
    void Move(int direction)
    {
        std::cout << "Player direction "
                  << direction << '\n';
    }
};

int main()
{
    Player player;
    player.Move(1);

    Character& character = player;
    character.Move(10.0f, 20.0f);
}
