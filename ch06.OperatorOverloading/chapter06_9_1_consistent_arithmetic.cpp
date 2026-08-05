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

public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

Vector3 operator+(Vector3 left, const Vector3& right)
{
    left += right;
    return left;
}

int main()
{
    Vector3 first(10.0f, 20.0f, 30.0f);
    Vector3 second(1.0f, 2.0f, 3.0f);

    Vector3 compound = first;
    compound += second;

    Vector3 binary = first + second;

    std::cout << compound.x << ", "
              << compound.y << ", "
              << compound.z << '\n';
    std::cout << binary.x << ", "
              << binary.y << ", "
              << binary.z << '\n';
}
