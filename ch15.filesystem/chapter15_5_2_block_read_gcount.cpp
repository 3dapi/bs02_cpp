#include <array>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    const std::filesystem::path path = "chapter15_block.bin";

    {
        std::ofstream output{path, std::ios::binary};
        output.write("ABCDEFGHIJ", 10);
    }

    std::ifstream input{path, std::ios::binary};
    std::array<char, 4> buffer{};
    std::string result;

    while (input)
    {
        input.read(buffer.data(), buffer.size());
        const std::streamsize count = input.gcount();

        if (count > 0)
        {
            result.append(buffer.data(), static_cast<std::size_t>(count));
        }
    }

    std::cout << result << '\n';
    input.close();
    std::filesystem::remove(path);
}
