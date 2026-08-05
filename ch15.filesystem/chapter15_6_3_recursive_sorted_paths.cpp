#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

namespace fs = std::filesystem;

int main()
{
    const fs::path directory = "chapter15_tree";
    fs::create_directories(directory / "a");
    fs::create_directories(directory / "b");

    std::ofstream{directory / "b" / "second.txt"} << "2";
    std::ofstream{directory / "a" / "first.txt"} << "1";

    std::vector<fs::path> paths;

    for (const fs::directory_entry& entry :
         fs::recursive_directory_iterator{directory})
    {
        if (entry.is_regular_file())
        {
            paths.push_back(entry.path());
        }
    }

    std::ranges::sort(paths);

    for (const fs::path& path : paths)
    {
        std::cout << path.generic_string() << '\n';
    }

    fs::remove_all(directory);
}
