#include <iostream>

class Length
{
public:
    explicit Length(int value, int scale = 1)
        : value(value * scale)
    {
    }

    int Value() const
    {
        return value;
    }

private:
    int value;
};

int main()
{
    Length first(100);
    Length second(100, 10);

    // Length third = 100;   // 오류

    std::cout << first.Value() << '\n';
    std::cout << second.Value() << '\n';
}
