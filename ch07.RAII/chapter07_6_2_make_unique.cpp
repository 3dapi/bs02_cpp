#include <iostream>
#include <memory>

class Enemy
{
public:
    Enemy(int hp, int attack)
        : hp(hp), attack(attack)
    {
    }

    void Print() const
    {
        std::cout << hp << ' '
                  << attack << '\n';
    }

private:
    int hp;
    int attack;
};

int main()
{
    auto enemy =
        std::make_unique<Enemy>(100, 20);

    enemy->Print();

    auto value = std::make_unique<int>();

    std::cout << *value << '\n';
}
