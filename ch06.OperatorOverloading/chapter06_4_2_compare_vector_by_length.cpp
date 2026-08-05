#include <iostream>

class Vector3
{
public:
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    float LengthSquared() const
    {
        return x * x + y * y + z * z;
    }

public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

struct CompareVectorByLength
{
    bool operator()(
        const Vector3& first,
        const Vector3& second
    ) const
    {
        return first.LengthSquared()
             < second.LengthSquared();
    }
};

int main()
{
    Vector3 first(1.0f, 2.0f, 3.0f);
    Vector3 second(10.0f, 0.0f, 0.0f);

    CompareVectorByLength compare;

    std::cout << std::boolalpha
              << compare(first, second) << '\n';
}
