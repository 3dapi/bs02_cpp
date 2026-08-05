#include <array>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

struct PlayerRecord
{
    std::uint32_t id;
    std::string name;
    std::uint32_t hp;
};

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

int main()
{
    const std::filesystem::path path = "chapter15_fields.bin";
    PlayerRecord player{1, "Knight", 100};

    {
        std::ofstream output{path, std::ios::binary};
        WriteUint32LE(output, player.id);
        WriteUint32LE(output, static_cast<std::uint32_t>(player.name.size()));
        output.write(player.name.data(), static_cast<std::streamsize>(player.name.size()));
        WriteUint32LE(output, player.hp);
    }

    std::cout << std::filesystem::file_size(path) << '\n';
    std::filesystem::remove(path);
}
