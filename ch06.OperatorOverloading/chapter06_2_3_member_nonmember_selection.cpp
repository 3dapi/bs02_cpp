#include <iostream>

class Vector3
{
public:
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    Vector3& operator+=(const Vector3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;

        return *this;
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

int main()
{
    Vector3 first(1.0f, 2.0f, 3.0f);
    Vector3 second(4.0f, 5.0f, 6.0f);

    first += second;

    Vector3 result1 = first * 2.0f;
    Vector3 result2 = 2.0f * first;

    std::cout << result1.x << ", "
              << result1.y << ", "
              << result1.z << '\n';
    std::cout << result2.x << ", "
              << result2.y << ", "
              << result2.z << '\n';
}
