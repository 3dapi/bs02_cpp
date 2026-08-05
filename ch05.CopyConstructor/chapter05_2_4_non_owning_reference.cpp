#include <iostream>

class Player
{
public:
    void SetHp(int hp)
    {
        this->hp = hp;
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp = 100;
};

class PlayerView
{
public:
    explicit PlayerView(Player* player)
        : player(player)
    {
    }

    int GetHp() const
    {
        return player != nullptr ? player->GetHp() : 0;
    }

private:
    Player* player = nullptr;
};

int main()
{
    Player player;
    PlayerView first(&player);
    PlayerView second = first;

    player.SetHp(70);

    std::cout << first.GetHp() << '\n';
    std::cout << second.GetHp() << '\n';
}
