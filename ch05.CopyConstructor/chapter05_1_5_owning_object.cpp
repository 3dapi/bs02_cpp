#include <cstddef>
#include <iostream>

class IntArray
{
public:
    explicit IntArray(std::size_t size)
        : size(size),
          data(size > 0 ? new int[size]{} : nullptr)
    {
    }

    ~IntArray()
    {
        delete[] data;
    }

    std::size_t GetSize() const
    {
        return size;
    }

private:
    std::size_t size = 0;
    int* data = nullptr;
};

int main()
{
    IntArray values(3);
    std::cout << values.GetSize() << '\n';
}
