#include <functional>
#include <iostream>

class Player
{
public:
    explicit Player(int hp) : hp(hp) { }
    void TakeDamage(int damage)
    {
        hp -= damage;
    }
    int GetHp() const
    {
        return hp;
    }
private:
    int hp;
};

int main()
{
    Player player{100};
    auto takeDamage = std::mem_fn(&Player::TakeDamage);
    auto getHp = std::mem_fn(&Player::GetHp);
    takeDamage(player, 30);
    std::cout << getHp(player) << '\n';
}
