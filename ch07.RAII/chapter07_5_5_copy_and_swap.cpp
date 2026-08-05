#include <cstddef>
#include <iostream>
#include <utility>

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
          data(other.size > 0
              ? new int[other.size]
              : nullptr)
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

        IntArray copy(other);

        Swap(copy);

        return *this;
    }

    void Swap(IntArray& other) noexcept
    {
        using std::swap;

        swap(size, other.size);
        swap(data, other.data);
    }

    void Set(std::size_t index, int value)
    {
        if (index < size)
        {
            data[index] = value;
        }
    }

    int Get(std::size_t index) const
    {
        if (index < size)
        {
            return data[index];
        }

        return 0;
    }

private:
    std::size_t size = 0;
    int* data = nullptr;
};

int main()
{
    IntArray first(2);
    IntArray second(1);

    first.Set(0, 10);
    first.Set(1, 20);

    second = first;

    std::cout << second.Get(0) << ' '
              << second.Get(1) << '\n';
}
