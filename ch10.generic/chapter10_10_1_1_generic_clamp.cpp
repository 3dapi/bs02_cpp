#include <iostream>

template <typename T>
T Clamp(T value, T minimum, T maximum)
{
    if (value < minimum)
    {
        return minimum;
    }

    if (maximum < value)
    {
        return maximum;
    }

    return value;
}

int main()
{
    int score = Clamp(1200, 0, 999);
    float speed = Clamp(12.5f, 0.0f, 10.0f);

    std::cout << score << '\n';
    std::cout << speed << '\n';
}
