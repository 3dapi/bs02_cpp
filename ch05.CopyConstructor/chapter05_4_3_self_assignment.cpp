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
        if (this == &other)
        {
            return *this;
        }

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
    Number number(10);
    number = number;

    std::cout << number.GetValue() << '\n';
}
