#include <iostream>
#include <string_view>

template <typename T>
struct TypeName
{
    static constexpr std::string_view Get()
    {
        return "unknown";
    }
};

template <>
struct TypeName<int>
{
    static constexpr std::string_view Get()
    {
        return "int";
    }
};

template <>
struct TypeName<double>
{
    static constexpr std::string_view Get()
    {
        return "double";
    }
};

int main()
{
    static_assert(TypeName<int>::Get() == "int");
    static_assert(TypeName<double>::Get() == "double");
    static_assert(TypeName<char>::Get() == "unknown");

    std::cout << TypeName<int>::Get() << '\n';
    std::cout << TypeName<char>::Get() << '\n';
}
