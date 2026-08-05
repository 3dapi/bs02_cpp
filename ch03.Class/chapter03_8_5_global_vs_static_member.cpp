#include <iostream>

int maxPlayerCount = 4;

class Player
{
public:
    static int GetMaxPlayerCount()
    {
        return classMaxPlayerCount;
    }

    static bool SetMaxPlayerCount(int count)
    {
        if (count < 1 || count > 100)
        {
            return false;
        }

        classMaxPlayerCount = count;
        return true;
    }

private:
    inline static int classMaxPlayerCount = 4;
};

int main()
{
    maxPlayerCount = 8;
    Player::SetMaxPlayerCount(8);

    std::cout << maxPlayerCount << '\n';
    std::cout << Player::GetMaxPlayerCount() << '\n';
}
