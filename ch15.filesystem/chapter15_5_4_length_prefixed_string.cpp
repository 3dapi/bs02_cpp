#include <array>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>
#include <optional>
#include <stdexcept>
#include <string>

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

void WriteString(std::ostream& output, const std::string& text)
{
    if (text.size() > std::numeric_limits<std::uint32_t>::max())
    {
        throw std::length_error{"String is too long"};
    }

    WriteUint32LE(
        output,
        static_cast<std::uint32_t>(text.size()));

    output.write(
        text.data(),
        static_cast<std::streamsize>(text.size()));
}

std::optional<std::string> ReadString(std::istream& input)
{
    constexpr std::uint32_t maxLength = 1024 * 1024;

    auto length = ReadUint32LE(input);
    if (!length || *length > maxLength)
    {
        return std::nullopt;
    }

    std::string text(*length, '\0');
    input.read(
        text.data(),
        static_cast<std::streamsize>(text.size()));

    if (!input)
    {
        return std::nullopt;
    }

    return text;
}

int main()
{
    const std::filesystem::path path = "chapter15_string.bin";

    {
        std::ofstream output{path, std::ios::binary};
        WriteString(output, "Knight");
    }

    std::ifstream input{path, std::ios::binary};
    auto text = ReadString(input);
    std::cout << text.value_or("error") << '\n';

    input.close();
    std::filesystem::remove(path);
}
