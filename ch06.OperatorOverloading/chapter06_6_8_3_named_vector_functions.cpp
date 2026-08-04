#include <cmath>
#include <iostream>

class Vector3
{
public:
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    float Length() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    float Dot(const Vector3& other) const
    {
        return x * other.x
             + y * other.y
             + z * other.z;
    }

    Vector3 Cross(const Vector3& other) const
    {
        return Vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

int main()
{
    Vector3 first(1.0f, 0.0f, 0.0f);
    Vector3 second(0.0f, 1.0f, 0.0f);

    float dot = first.Dot(second);
    Vector3 cross = first.Cross(second);

    std::cout << first.Length() << '\n';
    std::cout << dot << '\n';
    std::cout << cross.x << ", "
              << cross.y << ", "
              << cross.z << '\n';
}
