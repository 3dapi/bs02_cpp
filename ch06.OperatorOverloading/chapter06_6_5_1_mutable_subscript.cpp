#include <cstddef>
#include <iostream>

class Vector3
{
public:
    float& operator[](std::size_t index)
    {
        return values[index];
    }

public:
    float values[3] = {};
};

int main()
{
    Vector3 vector;

    vector[0] = 10.0f;
    vector[1] = 20.0f;
    vector[2] = 30.0f;

    std::cout << vector[0] << ", "
              << vector[1] << ", "
              << vector[2] << '\n';
}
