#include <iostream>

class Health
{
public:
    explicit Health(int value)
        : value(value < 0 ? 0 : value)
    {
    }

    int Get() const
    {
        return value;
    }

private:
    int value;
};

int main()
{
    Health first{100};
    Health second{-20};

    std::cout << first.Get() << ' '
              << second.Get() << '\n';
}
