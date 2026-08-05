#include <type_traits>

template <typename T>
struct IsPointer
{
    static constexpr bool value = false;
};

template <typename T>
struct IsPointer<T*>
{
    static constexpr bool value = true;
};

template <typename T>
inline constexpr bool IsPointerValue = IsPointer<T>::value;

int main()
{
    static_assert(std::is_integral_v<int>);
    static_assert(!std::is_integral_v<double>);
    static_assert(!IsPointer<int>::value);
    static_assert(IsPointer<int*>::value);
    static_assert(IsPointerValue<double*>);
    static_assert(std::true_type::value);
    static_assert(!std::false_type::value);
}
