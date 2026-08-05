#include <memory>
#include <type_traits>

template <typename T>
void RequireMovable()
{
    static_assert(
        std::is_move_constructible_v<T>,
        "T must be move constructible");
}

int main()
{
    RequireMovable<int>();
    RequireMovable<std::unique_ptr<int>>();
}
