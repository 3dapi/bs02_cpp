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

Vector3 operator+(Vector3 left, const Vector3& right)
{
    left += right;
    return left;
}

Vector3 operator*(Vector3 vector, float scalar)
{
    vector *= scalar;
    return vector;
}

int main()
{
    Vector3 start(10.0f, 20.0f, 30.0f);
    Vector3 velocity(2.0f, 1.0f, -1.0f);
    float deltaTime = 3.0f;

    Vector3 position = start + velocity * deltaTime;

    std::cout << position.x << ", "
              << position.y << ", "
              << position.z << '\n';
}
