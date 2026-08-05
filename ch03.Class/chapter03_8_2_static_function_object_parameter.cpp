#include <iostream>

class Player
{
public:
    static void Recover(Player& player, int amount)
    {
        if (amount > 0)
        {
            player.hp += amount;
        }
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp = 100;
};

int main()
{
    Player player;

    Player::Recover(player, 10);
    std::cout << player.GetHp() << '\n';
}
