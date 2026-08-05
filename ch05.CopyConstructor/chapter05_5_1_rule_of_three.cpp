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

    IntArray(const IntArray& other)
        : size(other.size),
          data(other.size > 0 ? new int[other.size] : nullptr)
    {
        for (std::size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    IntArray& operator=(const IntArray& other)
    {
        if (this == &other)
        {
            return *this;
        }

        int* newData =
            other.size > 0 ? new int[other.size] : nullptr;

        for (std::size_t i = 0; i < other.size; ++i)
        {
            newData[i] = other.data[i];
        }

        delete[] data;
        data = newData;
        size = other.size;

        return *this;
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
    IntArray first(3);
    IntArray second = first;
    IntArray third(10);
    third = second;

    std::cout << third.GetSize() << '\n';
}
