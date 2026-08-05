#include <iostream>

class Player
{
public:
    int GetHp() const
    {
        return hp;
    }

    void SetHp(int value)
    {
        hp = value;
    }

private:
    int hp = 100;
};

int main()
{
    Player player;

    player.SetHp(-1000);
    std::cout << player.GetHp() << '\n';
}
