#include <iostream>

class Size
{
public:
    explicit Size(int value)
        : value(value > 0 ? value : 0)
    {
    }

    Size& operator-=(int amount)
    {
        if (amount > value)
        {
            value = 0;
        }
        else if (amount > 0)
        {
            value -= amount;
        }

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
    Size size(10);

    size -= 3;
    std::cout << size.GetValue() << '\n';

    size -= 100;
    std::cout << size.GetValue() << '\n';
}
