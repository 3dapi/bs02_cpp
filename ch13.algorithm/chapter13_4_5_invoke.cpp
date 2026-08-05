#include <functional>
#include <iostream>

int Add(int left, int right)
{
    return left + right;
}

class Player
{
public:
    explicit Player(int hp)
        : hp(hp)
    {
    }

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

struct Item
{
    int id;
    int price;
};

int main()
{
	// Invoke:함수 포인터 호출.
    std::cout << std::invoke(Add, 10, 20) << '\n';

    // Invoke: 멤버 함수 포인터 호출.
    Player player{100};
    auto takeDamage = &Player::TakeDamage;
    auto getHp = &Player::GetHp;
    std::invoke(takeDamage, player, 30);
    std::cout << std::invoke(getHp, player) << '\n';

    // Invoke: 참조 호출.
    Item item{1001, 500};
    auto price = &Item::price;
    std::invoke(price, item) = 700;
    std::cout << item.price << '\n';
}
