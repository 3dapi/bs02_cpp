#include <concepts>
#include <iostream>

template <typename T>
concept HealthValue =
    std::integral<T> &&
    std::signed_integral<T>;

template <HealthValue T>
class Health
{
public:
    explicit Health(T maxHp)
        : hp(maxHp), maxHp(maxHp)
    {
    }

    T GetHp() const
    {
        return hp;
    }

private:
    T hp;
    T maxHp;
};

template <HealthValue T>
void PrintHealth(T hp)
{
    if constexpr (sizeof(T) <= sizeof(int))
    {
        std::cout << static_cast<int>(hp) << '\n';
    }
    else
    {
        std::cout << static_cast<long long>(hp) << '\n';
    }
}

int main()
{
    Health<int> health(100);
    PrintHealth(health.GetHp());
}
