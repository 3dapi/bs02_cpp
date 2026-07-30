#include <cstddef>
#include <iostream>
#include <utility>

class UniqueBuffer
{
public:
    explicit UniqueBuffer(std::size_t size)
        : size(size),
          data(size > 0 ? new int[size]{} : nullptr)
    {
    }

    ~UniqueBuffer()
    {
        delete[] data;
    }

    UniqueBuffer(const UniqueBuffer&) = delete;
    UniqueBuffer& operator=(const UniqueBuffer&) = delete;

    UniqueBuffer(UniqueBuffer&& other) noexcept
        : size(other.size),
          data(other.data)
    {
        other.size = 0;
        other.data = nullptr;
    }

    UniqueBuffer& operator=(UniqueBuffer&& other) noexcept
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

    std::size_t GetSize() const
    {
        return size;
    }

private:
    std::size_t size = 0;
    int* data = nullptr;
};

UniqueBuffer CreateBuffer()
{
    return UniqueBuffer(1024);
}

int main()
{
    UniqueBuffer buffer = CreateBuffer();
    std::cout << buffer.GetSize() << '\n';
}
