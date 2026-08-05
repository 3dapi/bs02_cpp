#include <iostream>

class Vector3
{
public:
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

Vector3 operator+(const Vector3& first, const Vector3& second)
{
    return Vector3(
        first.x + second.x,
        first.y + second.y,
        first.z + second.z
    );
}

Vector3 operator*(const Vector3& vector, float scalar)
{
    return Vector3(
        vector.x * scalar,
        vector.y * scalar,
        vector.z * scalar
    );
}

int main()
{
    Vector3 first(1.0f, 2.0f, 3.0f);
    Vector3 second(4.0f, 5.0f, 6.0f);
    Vector3 result = first + second * 2.0f;

    std::cout << result.x << ", "
              << result.y << ", "
              << result.z << '\n';
}
