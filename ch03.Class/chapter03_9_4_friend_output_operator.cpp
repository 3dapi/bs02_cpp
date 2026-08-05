#include <iostream>
#include <ostream>

class Vector2
{
public:
    Vector2(float x, float y)
        : x(x), y(y)
    {
    }

    friend std::ostream& operator<<(
        std::ostream& output,
        const Vector2& value);

public:
    float x, y;
};

std::ostream& operator<<(
    std::ostream& output,
    const Vector2& value)
{
    output << '('
           << value.x << ", "
           << value.y << ')';

    return output;
}

int main()
{
    Vector2 position(10.0f, 20.0f);

    std::cout << position << '\n';
}
