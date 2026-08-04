#include <cstddef>
#include <iostream>
#include <stdexcept>

class Vector3
{
public:
    Vector3(float x, float y, float z)
        : values{x, y, z}
    {
    }

    float& At(std::size_t index)
    {
        if (index >= 3)
        {
            throw std::out_of_range("Vector3 index");
        }

        return values[index];
    }

    const float& At(std::size_t index) const
    {
        if (index >= 3)
        {
            throw std::out_of_range("Vector3 index");
        }

        return values[index];
    }

public:
    float values[3] = {};
};

int main()
{
    Vector3 vector(10.0f, 20.0f, 30.0f);

    try
    {
        vector.At(3) = 100.0f;
    }
    catch (const std::out_of_range& error)
    {
        std::cout << error.what() << '\n';
    }
}
