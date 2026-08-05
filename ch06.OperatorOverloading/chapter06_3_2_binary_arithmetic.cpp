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

Vector3 operator+(Vector3 left, const Vector3& right)
{
    left += right;
    return left;
}

Vector3 operator-(Vector3 left, const Vector3& right)
{
    left -= right;
    return left;
}

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
    Vector3 first(10.0f, 20.0f, 30.0f);
    Vector3 second(1.0f, 2.0f, 3.0f);

    Vector3 sum = first + second;
    Vector3 difference = first - second;
    Vector3 scaled = 2.0f * first;

    std::cout << sum.x << ", " << sum.y << ", " << sum.z << '\n';
    std::cout << difference.x << ", " << difference.y << ", " << difference.z << '\n';
    std::cout << scaled.x << ", " << scaled.y << ", " << scaled.z << '\n';
}
