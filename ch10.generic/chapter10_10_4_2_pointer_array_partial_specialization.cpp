#include <cstddef>
#include <iostream>
#include <string_view>

template <typename T>
struct TypeCategory
{
    static constexpr std::string_view Get()
    {
        return "value";
    }
};

template <typename T>
struct TypeCategory<T*>
{
    static constexpr std::string_view Get()
    {
        return "pointer";
    }
};

template <typename T, std::size_t Size>
struct TypeCategory<T[Size]>
{
    static constexpr std::string_view Get()
    {
        return "fixed array";
    }

    static constexpr std::size_t GetSize()
    {
        return Size;
    }
};

int main()
{
    static_assert(TypeCategory<int>::Get() == "value");
    static_assert(TypeCategory<int*>::Get() == "pointer");
    static_assert(TypeCategory<int[5]>::Get() == "fixed array");
    static_assert(TypeCategory<int[5]>::GetSize() == 5);

    std::cout << TypeCategory<double*>::Get() << '\n';
    std::cout << TypeCategory<int[5]>::GetSize() << '\n';
}
