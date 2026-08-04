#include <iostream>

class Length
{
public:
    explicit Length(double meters)
        : meters(meters)
    {
    }

    explicit operator double() const
    {
        return meters;
    }

private:
    double meters = 0.0;
};

int main()
{
    Length length(3.5);

    double first = static_cast<double>(length);
    double second(length);

    std::cout << first << '\n';
    std::cout << second << '\n';
}
