#include <iostream>

class Player
{
public:
    static void SetMaxPlayerCount(int count)
    {
        if (count > 0)
        {
            maxPlayerCount = count;
        }
    }

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
    Player::SetMaxPlayerCount(8);
    std::cout << Player::GetMaxPlayerCount() << '\n';
}
