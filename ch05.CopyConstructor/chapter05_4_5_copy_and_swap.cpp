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
          data(other.size > 0 ? new int[other.size] : nullptr)
    {
        for (std::size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    IntArray& operator=(IntArray other)
    {
        Swap(other);
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
        return index < size ? data[index] : 0;
    }

private:
    std::size_t size = 0;
    int* data = nullptr;
};

int main()
{
    IntArray first(2);
    first.Set(0, 10);

    IntArray second(4);
    second = first;

    std::cout << second.Get(0) << '\n';
}
