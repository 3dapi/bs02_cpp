#include <iostream>
#include <stdexcept>

class IDamageable
{
public:
    virtual ~IDamageable() = default;

    // damage >= 0이면 호출 가능
    // 반환값은 실제로 감소한 체력
    virtual int TakeDamage(int damage) = 0;
};

class FragileObject : public IDamageable
{
public:
    int TakeDamage(int damage) override
    {
        if (damage > 100)
        {
            throw std::invalid_argument(
                "damage must not exceed 100");
        }

        return damage;
    }
};

int main()
{
    FragileObject object;

    try
    {
        std::cout << object.TakeDamage(200) << '\n';
    }
    catch (const std::invalid_argument& error)
    {
        std::cout << error.what() << '\n';
    }
}
