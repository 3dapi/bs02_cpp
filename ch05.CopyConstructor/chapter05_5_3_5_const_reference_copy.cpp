#include <iostream>

class Number
{
public:
    explicit Number(int value)
        : value(value)
    {
    }

    Number(const Number& other)
        : value(other.value)
    {
    }

    int GetValue() const
    {
        return value;
    }

private:
    int value = 0;
};

int main()
{
    Number normal(10);
    const Number fixed(20);

    Number first(normal);
    Number second(fixed);

    std::cout << first.GetValue() << '\n';
    std::cout << second.GetValue() << '\n';
}
