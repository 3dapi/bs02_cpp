#include <iostream>

class Length
{
public:
    explicit Length(double meters)
        : meters(meters)
    {
    }

    double GetMeters() const
    {
        return meters;
    }

private:
    double meters = 0.0;
};

int main()
{
    Length length(3.5);

    std::cout << length.GetMeters() << '\n';
}
