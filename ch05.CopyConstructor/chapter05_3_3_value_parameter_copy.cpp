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

void PrintByValue(Number number)
{
    std::cout << number.GetValue() << '\n';
}

void PrintByReference(const Number& number)
{
    std::cout << number.GetValue() << '\n';
}

int main()
{
    Number number(10);

    PrintByValue(number);
    PrintByReference(number);
}
