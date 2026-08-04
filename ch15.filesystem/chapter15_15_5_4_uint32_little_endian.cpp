#include <array>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>

void WriteUint32LE(std::ostream& output, std::uint32_t value)
{
    std::array<unsigned char, 4> bytes{
        static_cast<unsigned char>(value & 0xFFu),
        static_cast<unsigned char>((value >> 8) & 0xFFu),
        static_cast<unsigned char>((value >> 16) & 0xFFu),
        static_cast<unsigned char>((value >> 24) & 0xFFu)
    };

    output.write(
        reinterpret_cast<const char*>(bytes.data()),
        static_cast<std::streamsize>(bytes.size()));
}

std::optional<std::uint32_t> ReadUint32LE(std::istream& input)
{
    std::array<unsigned char, 4> bytes{};

    input.read(
        reinterpret_cast<char*>(bytes.data()),
        static_cast<std::streamsize>(bytes.size()));

    if (!input)
    {
        return std::nullopt;
    }

    std::uint32_t value =
        static_cast<std::uint32_t>(bytes[0]) |
        (static_cast<std::uint32_t>(bytes[1]) << 8) |
        (static_cast<std::uint32_t>(bytes[2]) << 16) |
        (static_cast<std::uint32_t>(bytes[3]) << 24);

    return value;
}

int main()
{
    const std::filesystem::path path = "chapter15_uint32.bin";

    {
        std::ofstream output{path, std::ios::binary};
        WriteUint32LE(output, 0x12345678u);
    }

    std::ifstream input{path, std::ios::binary};
    auto value = ReadUint32LE(input);

    if (value)
    {
        std::cout << std::hex << *value << '\n';
    }

    input.close();
    std::filesystem::remove(path);
}
