#include <array>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <stdexcept>

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

    return static_cast<std::uint32_t>(bytes[0]) |
           (static_cast<std::uint32_t>(bytes[1]) << 8) |
           (static_cast<std::uint32_t>(bytes[2]) << 16) |
           (static_cast<std::uint32_t>(bytes[3]) << 24);
}

int main()
{
    const std::filesystem::path path = "chapter15_header.bin";

    {
        std::ofstream output{path, std::ios::binary};
        output.write("PLYR", 4);
        WriteUint32LE(output, 2);
    }

    std::ifstream input{path, std::ios::binary};
    std::array<char, 4> magic{};
    input.read(magic.data(), static_cast<std::streamsize>(magic.size()));

    if (!input || magic != std::array<char, 4>{'P', 'L', 'Y', 'R'})
    {
        throw std::runtime_error{"Invalid file type"};
    }

    auto version = ReadUint32LE(input);
    if (!version)
    {
        throw std::runtime_error{"Invalid file header"};
    }

    switch (*version)
    {
    case 1:
        std::cout << "version 1\n";
        break;

    case 2:
        std::cout << "version 2\n";
        break;

    default:
        throw std::runtime_error{"Unsupported file version"};
    }

    input.close();
    std::filesystem::remove(path);
}
