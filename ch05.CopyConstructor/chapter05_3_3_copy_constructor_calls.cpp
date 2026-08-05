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
        std::cout << "copy\n";
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
    Number original(10);
    Number first(original);
    Number second = original;

    std::cout << first.GetValue() + second.GetValue() << '\n';
}
