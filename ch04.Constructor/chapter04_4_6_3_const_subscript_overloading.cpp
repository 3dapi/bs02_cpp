#include <cstddef>
#include <iostream>

class IntArray
{
public:
    int& operator[](std::size_t index)
    {
        return values[index];
    }

    const int& operator[](std::size_t index) const
    {
        return values[index];
    }

private:
    int values[3] = {10, 20, 30};
};

int main()
{
    IntArray values;
    values[0] = 100;

    const IntArray fixedValues;

    std::cout << values[0] << '\n';
    std::cout << fixedValues[1] << '\n';
}
