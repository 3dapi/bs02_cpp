#include <iostream>

class Vector3
{
public:
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    float GetX() const
    {
        return x;
    }

    float GetY() const
    {
        return y;
    }

    float GetZ() const
    {
        return z;
    }

private:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

std::ostream& operator<<(
    std::ostream& output,
    const Vector3& vector
)
{
    output << '('
           << vector.GetX() << ", "
           << vector.GetY() << ", "
           << vector.GetZ() << ')';

    return output;
}

int main()
{
    Vector3 first(10.0f, 20.0f, 30.0f);
    Vector3 second(1.0f, 2.0f, 3.0f);

    std::cout << first << ' ' << second << '\n';
}
