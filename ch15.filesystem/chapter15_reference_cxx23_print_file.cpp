#include <cstdio>
#include <filesystem>
#include <print>

int main()
{
    const std::filesystem::path path = "chapter15_log.txt";
    std::FILE* file = std::fopen(path.string().c_str(), "w");

    if (file == nullptr)
    {
        return 1;
    }

    std::println(file, "Player {} joined", "Knight");
    std::fclose(file);

    std::filesystem::remove(path);
}
