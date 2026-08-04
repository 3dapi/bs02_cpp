#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>

int main()
{
    const std::filesystem::path path = "chapter15_score.bin";
    std::int32_t score = 1500;

    {
        std::ofstream output{
            path,
            std::ios::out | std::ios::binary};

        output.write(
            reinterpret_cast<const char*>(&score),
            sizeof(score));
    }

    score = 0;

    std::ifstream input{
        path,
        std::ios::in | std::ios::binary};

    input.read(
        reinterpret_cast<char*>(&score),
        sizeof(score));

    if (input)
    {
        std::cout << score << '\n';
    }

    input.close();
    std::filesystem::remove(path);
}
