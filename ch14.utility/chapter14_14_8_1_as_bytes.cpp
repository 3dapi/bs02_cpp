#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <span>

int main()
{
    std::array<std::uint32_t, 2> values{
        0x12345678u,
        0x90ABCDEFu
    };

    std::span<const std::byte> bytes =
        std::as_bytes(std::span{values});

    std::span<std::byte> writable =
        std::as_writable_bytes(std::span{values});

    std::cout << bytes.size() << ' '
              << writable.size() << '\n';
}
