#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

void SaveTextAtomically(
    const std::filesystem::path& path,
    const std::string& text)
{
    std::filesystem::path temporary = path;
    temporary += ".tmp";

    {
        std::ofstream output{temporary};
        if (!output)
        {
            throw std::runtime_error{"Temporary file open failed"};
        }

        output << text;
        if (!output)
        {
            throw std::runtime_error{"Temporary file write failed"};
        }
    }

    std::error_code error;
    std::filesystem::remove(path, error);
    error.clear();
    std::filesystem::rename(temporary, path, error);

    if (error)
    {
        throw std::filesystem::filesystem_error{
            "File replacement failed",
            temporary,
            path,
            error};
    }
}

int main()
{
    const std::filesystem::path path = "chapter15_atomic.txt";
    SaveTextAtomically(path, "saved text\n");

    std::ifstream input{path};
    std::string line;
    std::getline(input, line);
    std::cout << line << '\n';

    input.close();
    std::filesystem::remove(path);
}
