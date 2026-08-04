#include <iostream>
#include <sstream>

class Vector3
{
public:
    Vector3() = default;

    Vector3(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

std::istream& operator>>(
    std::istream& input,
    Vector3& vector
)
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    if (input >> x >> y >> z)
    {
        vector = Vector3(x, y, z);
    }

    return input;
}

int main()
{
    Vector3 position(10.0f, 20.0f, 30.0f);
    std::istringstream input("1 2 3");

    if (input >> position)
    {
        std::cout << position.x << ", "
                  << position.y << ", "
                  << position.z << '\n';
    }
}
