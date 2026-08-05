#include <cstddef>
#include <iostream>

class Vector3
{
public:
    Vector3(float x, float y, float z)
        : values{x, y, z}
    {
    }

    float& operator[](std::size_t index)
    {
        return values[index];
    }

    const float& operator[](std::size_t index) const
    {
        return values[index];
    }

public:
    float values[3] = {};
};

int main()
{
    Vector3 vector(10.0f, 20.0f, 30.0f);
    vector[0] = 100.0f;

    const Vector3 fixedVector(1.0f, 2.0f, 3.0f);
    float x = fixedVector[0];

    std::cout << vector[0] << '\n';
    std::cout << x << '\n';
}
