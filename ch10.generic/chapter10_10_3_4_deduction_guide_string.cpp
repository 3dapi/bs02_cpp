#include <iostream>
#include <string>
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

ValueBox(const char*) -> ValueBox<std::string>;

int main()
{
    ValueBox name("Knight");

    static_assert(
        std::is_same_v<decltype(name), ValueBox<std::string>>);

    std::cout << name.GetValue() << '\n';
}
