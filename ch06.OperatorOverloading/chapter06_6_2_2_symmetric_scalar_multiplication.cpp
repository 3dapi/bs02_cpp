#include <iostream>

class Vector3
{
public:
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    Vector3& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;

        return *this;
    }

public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

Vector3 operator*(Vector3 vector, float scalar)
{
    vector *= scalar;
    return vector;
}

Vector3 operator*(float scalar, Vector3 vector)
{
    vector *= scalar;
    return vector;
}

void Print(const Vector3& vector)
{
    std::cout << vector.x << ", "
              << vector.y << ", "
              << vector.z << '\n';
}

int main()
{
    Vector3 value(1.0f, 2.0f, 3.0f);

    Vector3 first = value * 2.0f;
    Vector3 second = 2.0f * value;

    Print(first);
    Print(second);
}
