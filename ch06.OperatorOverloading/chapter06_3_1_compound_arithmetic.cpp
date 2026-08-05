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

    Vector3& operator-=(const Vector3& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;

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

int main()
{
    Vector3 first(10.0f, 20.0f, 30.0f);
    Vector3 second(1.0f, 2.0f, 3.0f);

    (first += second) *= 2.0f;
    first -= second;

    std::cout << first.x << ", "
              << first.y << ", "
              << first.z << '\n';
}
