#include <cstdint>
#include <iostream>

template <typename T>
class Storage
{
public:
    void Set(const T& value)
    {
        this->value = value;
    }

    const T& Get() const
    {
        return value;
    }

private:
    T value{};
};

template <>
class Storage<bool>
{
public:
    void Set(bool value)
    {
        bits = value ? 1u : 0u;
    }

    bool Get() const
    {
        return bits != 0;
    }

private:
    std::uint8_t bits = 0;
};

int main()
{
    Storage<int> number;
    Storage<bool> enabled;

    number.Set(100);
    enabled.Set(true);

    std::cout << number.Get() << '\n';
    std::cout << std::boolalpha << enabled.Get() << '\n';
}
