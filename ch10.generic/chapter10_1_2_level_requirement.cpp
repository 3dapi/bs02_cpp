#include <iostream>

class Level
{
public:
    explicit Level(int value)
        : value(value)
    {
    }

    int GetValue() const
    {
        return value;
    }

    friend bool operator<(const Level& left, const Level& right)
    {
        return left.value < right.value;
    }

private:
    int value;
};

template <typename T>
T Clamp(T value, T minimum, T maximum)
{
    return (value < minimum)? minimum
          :(maximum < value)? maximum : value;
}

int main()
{
    Level current(120);
    Level minimum(1);
    Level maximum(99);

    Level result = Clamp(current, minimum, maximum);
    std::cout << result.GetValue() << '\n';
}
