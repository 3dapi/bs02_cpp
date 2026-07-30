#include <cstddef>
#include <iostream>
#include <utility>

class IntArray
{
public:
    IntArray() = default;

    explicit IntArray(std::size_t size)
        : size(size),
          data(size > 0 ? new int[size]{} : nullptr)
    {
    }

    ~IntArray()
    {
        delete[] data;
    }

    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    IntArray(IntArray&& other) noexcept
        : size(other.size),
          data(other.data)
    {
        other.size = 0;
        other.data = nullptr;
    }

    IntArray& operator=(IntArray&& other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] data;
        size = other.size;
        data = other.data;
        other.size = 0;
        other.data = nullptr;

        return *this;
    }

    bool IsEmpty() const
    {
        return size == 0;
    }

private:
    std::size_t size = 0;
    int* data = nullptr;
};

int main()
{
    IntArray source(10);
    IntArray target(std::move(source));

    source = IntArray(5);

    std::cout << std::boolalpha;
    std::cout << source.IsEmpty() << '\n';
    std::cout << target.IsEmpty() << '\n';
}
