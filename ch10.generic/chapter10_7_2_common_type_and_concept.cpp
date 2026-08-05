#include <cstdint>
#include <iostream>
#include <type_traits>

using Selected = std::conditional_t<
    (sizeof(void*) == 8),
    std::uint64_t,
    std::uint32_t>;

template <typename Left, typename Right>
std::common_type_t<Left, Right>
AddCommon(const Left& left, const Right& right)
{
    using Result = std::common_type_t<Left, Right>;
    return static_cast<Result>(left) + static_cast<Result>(right);
}

template <typename T>
concept SmallTrivialValue =
    std::is_trivially_copyable_v<T> &&
    sizeof(T) <= 16;

int main()
{
    using Common = std::common_type_t<int, double>;

    static_assert(std::is_same_v<Common, double>);
    static_assert(sizeof(Selected) == sizeof(void*));
    static_assert(SmallTrivialValue<int>);

    std::cout << AddCommon(10, 2.5) << '\n';
}
