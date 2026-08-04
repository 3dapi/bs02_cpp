#include <chrono>
#include <iostream>
#include <type_traits>

int main()
{
    using namespace std::chrono_literals;

    auto total = 2s + 500ms;

    static_assert(
        std::is_same_v<decltype(total), std::chrono::milliseconds>);

    std::cout << total.count() << " ms\n";
}
