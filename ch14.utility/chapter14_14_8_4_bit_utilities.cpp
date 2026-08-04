#include <bit>
#include <cstdint>
#include <iostream>

int main()
{
    std::uint32_t value = 0b0010'1000;

    std::cout << std::popcount(value) << '\n';
    std::cout << std::boolalpha
              << std::has_single_bit(std::uint32_t{64})
              << '\n';
    std::cout << std::bit_width(std::uint32_t{100}) << '\n';
    std::cout << std::bit_floor(std::uint32_t{100}) << ' '
              << std::bit_ceil(std::uint32_t{100}) << '\n';
    std::cout << std::countl_zero(value) << ' '
              << std::countr_zero(value) << '\n';
    std::cout << std::rotl(value, 3) << '\n';
}
