#include <cstddef>
#include <iostream>

class IntArray
{
public:
    explicit IntArray(std::size_t size)
        : size(size)
    {
    }

    std::size_t GetSize() const
    {
        return size;
    }

private:
    std::size_t size = 0;
};

IntArray CreateArray(std::size_t size)
{
    return IntArray(size);
}

int main()
{
    IntArray values = CreateArray(1000);
    std::cout << values.GetSize() << '\n';
}
