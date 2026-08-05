#include <algorithm>
#include <ranges>
#include <type_traits>
#include <vector>

int main()
{
    using Result = decltype(std::ranges::find(
        std::vector<int>{1, 2, 3},
        2));

    static_assert(std::is_same_v<Result, std::ranges::dangling>);
}
