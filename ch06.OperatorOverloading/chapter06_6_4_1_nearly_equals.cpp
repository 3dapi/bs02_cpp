#include <cmath>
#include <iostream>

class Vector3
{
public:
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    bool operator==(const Vector3& other) const
    {
        return x == other.x
            && y == other.y
            && z == other.z;
    }

    bool NearlyEquals(
        const Vector3& other,
        float epsilon = 0.0001f
    ) const
    {
        return std::fabs(x - other.x) <= epsilon
            && std::fabs(y - other.y) <= epsilon
            && std::fabs(z - other.z) <= epsilon;
    }

public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

int main()
{
    float accumulated = 0.0f;

    for (int i = 0; i < 10; ++i)
    {
        accumulated += 0.1f;
    }

    Vector3 calculated(accumulated, 0.0f, 0.0f);
    Vector3 expected(1.0f, 0.0f, 0.0f);

    std::cout << std::boolalpha;
    std::cout << (calculated == expected) << '\n';
    std::cout << calculated.NearlyEquals(expected) << '\n';
}
