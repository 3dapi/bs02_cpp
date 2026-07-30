#include <iostream>

class Player
{
public:
    static int GetMaxPlayerCount()
    {
        return maxPlayerCount;
    }

private:
    static int maxPlayerCount;
};

int Player::maxPlayerCount = 4;

int main()
{
    std::cout << Player::GetMaxPlayerCount() << '\n';
    // Player::maxPlayerCount = 10; // 오류
}
