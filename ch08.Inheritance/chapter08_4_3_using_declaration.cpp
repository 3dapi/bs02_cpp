#include <iostream>

class Character
{
public:
    void Move(float distance)
    {
        std::cout << "Character: distance " << distance << '\n';
    }

    void Move(float x, float y)
    {
        std::cout << x << ", " << y << '\n';
    }
};

class Player : public Character
{
public:
    //using Character::Move;

    void Move(int direction)
    {
        std::cout << "Player: direction " << direction << '\n';
    }
};

int main()
{
    Player player;
    player.Move(1);
    player.Move(5.0f);
    player.Move(10.0f, 20.0f);
}
