#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    const fs::path path = "chapter15_status.txt";

    {
        std::ofstream output{path};
        output << "data";
    }

    std::error_code error;
    bool exists = fs::exists(path, error);

    if (error)
    {
        std::cerr << error.message() << '\n';
    }
    else if (exists && fs::is_regular_file(path))
    {
        std::cout << fs::file_size(path) << '\n';
    }

    fs::remove(path);
}
