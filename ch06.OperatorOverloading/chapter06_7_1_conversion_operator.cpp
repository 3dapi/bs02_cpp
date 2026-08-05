#include <iostream>

class Length
{
public:
    explicit Length(double meters)
        : meters(meters)
    {
    }

    operator double() const
    {
        return meters;
    }

private:
    double meters = 0.0;
};

void PrintMeters(double value)
{
    std::cout << value << " m\n";
}

int main()
{
    Length length(3.5);

    double meters = length;
    PrintMeters(length);

    std::cout << meters << '\n';
}
