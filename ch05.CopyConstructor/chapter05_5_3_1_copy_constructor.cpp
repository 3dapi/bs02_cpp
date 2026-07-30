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
        std::cout << "copy constructor\n";
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
    Number second(first);

    std::cout << second.GetValue() << '\n';
}
