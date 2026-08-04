#include <iostream>
#include <type_traits>
#include <utility>

template <typename T>
class ValueBox
{
public:
    explicit ValueBox(T value)
        : value(std::move(value))
    {
    }

    const T& GetValue() const
    {
        return value;
    }

private:
    T value;
};

int main()
{
    ValueBox first(10);
    ValueBox second(3.5);

    static_assert(std::is_same_v<decltype(first), ValueBox<int>>);
    static_assert(std::is_same_v<decltype(second), ValueBox<double>>);

    std::cout << first.GetValue() << '\n';
    std::cout << second.GetValue() << '\n';
}
