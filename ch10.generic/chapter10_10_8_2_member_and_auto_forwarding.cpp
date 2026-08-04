#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

template <typename T>
class Holder
{
public:
    explicit Holder(T value)
        : value(std::move(value))
    {
    }

    void Set(T&& value)
    {
        this->value = std::move(value);
    }

    template <typename U>
    void Assign(U&& value)
    {
        this->value = std::forward<U>(value);
    }

    const T& Get() const
    {
        return value;
    }

private:
    T value;
};

int main()
{
    int number = 10;
    const int limit = 20;

    auto&& first = number;
    auto&& second = limit;
    auto&& third = 30;

    static_assert(std::is_same_v<decltype(first), int&>);
    static_assert(std::is_same_v<decltype(second), const int&>);
    static_assert(std::is_same_v<decltype(third), int&&>);

    Holder<std::string> holder("Knight");
    std::string name = "Mage";

    holder.Assign(name);
    holder.Set(std::string("Rogue"));

    std::cout << holder.Get() << '\n';
}
