#include <iostream>

class Length
{
public:
    explicit Length(int value)
        : value(value)
    {
    }

    Length(double value) = delete;

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
    // Length second(3.14);   // 오류

    std::cout << first.Value() << '\n';
}
