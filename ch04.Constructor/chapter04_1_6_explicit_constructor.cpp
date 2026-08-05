#include <iostream>

class Length
{
public:
    explicit Length(int value)
        : value(value)
    {
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
    std::cout << length.Value() << '\n';
}

int main()
{
    Length first(100);
    Length second{200};

    // Length third = 300;   // 오류
    // PrintLength(400);     // 오류

    PrintLength(first);
    PrintLength(second);
    PrintLength(Length(400));
}
