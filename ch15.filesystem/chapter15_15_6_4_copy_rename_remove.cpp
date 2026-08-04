#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    const fs::path directory = "chapter15_files";
    fs::create_directory(directory);

    const fs::path source = directory / "source.txt";
    const fs::path copied = directory / "copied.txt";
    const fs::path renamed = directory / "renamed.txt";

    std::ofstream{source} << "data";

    fs::copy_file(
        source,
        copied,
        fs::copy_options::overwrite_existing);

    fs::rename(copied, renamed);
    std::cout << fs::exists(renamed) << '\n';

    fs::remove(source);
    fs::remove(renamed);
    fs::remove(directory);
}
