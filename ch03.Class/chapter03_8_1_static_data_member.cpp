#include <iostream>

class Player
{
public:
    int hp = 100;

    static int maxPlayerCount;
};

int Player::maxPlayerCount = 4;

int main()
{
    Player first;
    Player second;

    first.maxPlayerCount = 10;

    std::cout << Player::maxPlayerCount << '\n';
    std::cout << second.maxPlayerCount << '\n';
}
