#include <cstdio>
#include <iostream>

class FileHandle
{
public:
    explicit FileHandle(const char* fileName)
        : file(std::fopen(fileName, "w"))
    {
    }

    ~FileHandle() noexcept
    {
        Close();
    }

    bool IsOpen() const noexcept
    {
        return file != nullptr;
    }

private:
    void Close() noexcept
    {
        if (file != nullptr)
        {
            std::fclose(file);
            file = nullptr;
        }
    }

    std::FILE* file = nullptr;
};

int main()
{
    FileHandle file("chapter07_no_throw.txt");

    std::cout << std::boolalpha;
    std::cout << file.IsOpen() << '\n';
}
