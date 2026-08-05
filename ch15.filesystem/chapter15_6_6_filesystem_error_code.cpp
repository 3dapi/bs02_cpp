#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    const fs::path source = "chapter15_missing.txt";
    const fs::path destination = "chapter15_copy.txt";

    std::error_code error;
    fs::copy_file(
        source,
        destination,
        fs::copy_options::overwrite_existing,
        error);

    if (error)
    {
        std::cout << "Copy failed: " << error.message() << '\n';
    }
}
