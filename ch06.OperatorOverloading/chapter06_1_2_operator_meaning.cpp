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

    bool operator==(const Vector3& other) const
    {
        return x == other.x
            && y == other.y
            && z == other.z;
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
    Vector3 first(1.0f, 2.0f, 3.0f);
    Vector3 second(4.0f, 5.0f, 6.0f);

    Vector3 result = first + second;
    bool same = first == second;

    std::cout << result.x << ", "
              << result.y << ", "
              << result.z << '\n';
    std::cout << std::boolalpha << same << '\n';
}
