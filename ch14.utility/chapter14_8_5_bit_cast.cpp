#include <bit>
#include <cstdint>
#include <iostream>
#include <type_traits>

int main()
{
    static_assert(sizeof(float) == sizeof(std::uint32_t));
    static_assert(std::is_trivially_copyable_v<float>);
    static_assert(std::is_trivially_copyable_v<std::uint32_t>);

    float value = 1.0f;
    std::uint32_t numeric = static_cast<std::uint32_t>(value);
    std::uint32_t representation =
        std::bit_cast<std::uint32_t>(value);

    std::cout << numeric << '\n';
    std::cout << representation << '\n';
}
