#include <iostream>

class Length
{
public:
    explicit Length(int value, int scale = 1)
        : value(value * scale)
    {
        std::cout << "Length Constructor: " << value << '\n';
    }

    int Value() const
    {
        return value;
    }

private:
    int value;
};


void PrintLength(const Length& length)
{
    std::cout << "PrintLength: " << length.Value() << '\n';
}

int main()
{
    Length first(100);
    Length second(200, 10);

    std::cout << first.Value() << '\n';
    std::cout << second.Value() << '\n';

    // Length third = 300;   // 오류

    PrintLength(Length(400));
    //PrintLength(500);     // 오류
}
