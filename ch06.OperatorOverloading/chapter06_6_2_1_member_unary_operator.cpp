#include <iostream>

class Vector3
{
public:
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z)
    {
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

int main()
{
    Vector3 position(10.0f, -20.0f, 30.0f);
    Vector3 reversed = -position;

    std::cout << reversed.x << ", "
              << reversed.y << ", "
              << reversed.z << '\n';
}
