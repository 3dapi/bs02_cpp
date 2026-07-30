#include <iostream>

class Character
{
protected:
    int hp = 100;
};

class Player : public Character
{
public:
    void Recover()
    {
        hp += 10;
    }

    int GetHp() const
    {
        return hp;
    }
};

int main()
{
    Player player;

    player.Recover();
    std::cout << player.GetHp() << '\n';

    // player.hp = 200; // 오류
}
