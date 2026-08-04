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

Vector3 Add(const Vector3& first, const Vector3& second)
{
    return Vector3(
        first.x + second.x,
        first.y + second.y,
        first.z + second.z
    );
}

int main()
{
    Vector3 first(10.0f, 20.0f, 30.0f);
    Vector3 second(1.0f, 2.0f, 3.0f);
    Vector3 result = Add(first, second);

    std::cout << result.x << ", "
              << result.y << ", "
              << result.z << '\n';
}
