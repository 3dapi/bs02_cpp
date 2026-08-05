#include <iostream>

class Vector3
{
public:
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    Vector3 operator+() const
    {
        return *this;
    }

    Vector3 operator-() const
    {
        return Vector3(-x, -y, -z);
    }

public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

void Print(const Vector3& vector)
{
    std::cout << vector.x << ", "
              << vector.y << ", "
              << vector.z << '\n';
}

int main()
{
    Vector3 vector(10.0f, -20.0f, 30.0f);

    Print(+vector);
    Print(-vector);
}
