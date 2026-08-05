#include <concepts>
#include <initializer_list>
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

template <typename T>
class Wrapper
{
public:
    template <typename U>
    requires (!std::same_as<std::remove_cvref_t<U>, Wrapper>) &&
             std::constructible_from<T, U&&>
    explicit Wrapper(U&& value)
        : value(std::forward<U>(value))
    {
    }

    const T& Get() const
    {
        return value;
    }

private:
    T value;
};

void UseList(std::initializer_list<int> values)
{
    for (int value : values)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

template <typename T>
void RelayList(T&& value)
{
    UseList(std::forward<T>(value));
}

int main()
{
    Wrapper<std::string> wrapper("Knight");
    std::cout << wrapper.Get() << '\n';

    RelayList(std::initializer_list<int>{1, 2, 3});

    // RelayList({1, 2, 3}); // T를 추론할 수 없음
}
