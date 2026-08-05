#include <concepts>
#include <iostream>

template <std::integral T>
T DoubleValue(T value)
{
    return value * 2;
}

template <std::floating_point T>
T HalfValue(T value)
{
    return value / static_cast<T>(2);
}

template <typename T, typename U>
requires std::same_as<T, U>
bool AreSameTypeValues(const T& left, const U& right)
{
    return left == right;
}

template <typename From, typename To>
requires std::convertible_to<From, To>
To ConvertValue(const From& value)
{
    return static_cast<To>(value);
}

class GameObject
{
public:
    virtual ~GameObject() = default;
};

class Player : public GameObject
{
};

template <typename T>
requires std::derived_from<T, GameObject>
void RegisterGameObject(T& object)
{
    GameObject& base = object;
    std::cout << &base << '\n';
}

int main()
{
    Player player;

    std::cout << DoubleValue(10) << '\n';
    std::cout << HalfValue(10.0) << '\n';
    std::cout << std::boolalpha
              << AreSameTypeValues(10, 10) << '\n';
    std::cout << ConvertValue<int, double>(10) << '\n';

    RegisterGameObject(player);
}
