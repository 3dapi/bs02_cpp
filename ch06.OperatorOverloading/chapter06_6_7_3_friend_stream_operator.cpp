#include <iostream>
#include <sstream>

class Vector3
{
public:
    Vector3() = default;

    Vector3(float x, float y, float z)
        : values{x, y, z}
    {
    }

private:
    friend std::ostream& operator<<(
        std::ostream& output,
        const Vector3& vector
    );

    friend std::istream& operator>>(
        std::istream& input,
        Vector3& vector
    );

    float values[3] = {};
};

std::ostream& operator<<(
    std::ostream& output,
    const Vector3& vector
)
{
    output << vector.values[0] << ' '
           << vector.values[1] << ' '
           << vector.values[2];

    return output;
}

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
        vector.values[0] = x;
        vector.values[1] = y;
        vector.values[2] = z;
    }

    return input;
}

int main()
{
    Vector3 vector;
    std::istringstream input("10 20 30");

    input >> vector;
    std::cout << vector << '\n';
}
