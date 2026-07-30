#include <iostream>

class Number
{
public:
    explicit Number(int value)
        : value(value)
    {
    }

    Number& operator=(const Number& other)
    {
        value = other.value;
        return *this;
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
    Number first(10);
    Number second(20);
    Number third(30);

    first = second = third;

    std::cout << first.GetValue() << '\n';
    std::cout << second.GetValue() << '\n';
}
