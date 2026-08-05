#include <type_traits>

using LValue = int&;
using RValue = int&&;

using First = LValue&;
using Second = LValue&&;
using Third = RValue&;
using Fourth = RValue&&;

int main()
{
    static_assert(std::is_same_v<First, int&>);
    static_assert(std::is_same_v<Second, int&>);
    static_assert(std::is_same_v<Third, int&>);
    static_assert(std::is_same_v<Fourth, int&&>);
}
