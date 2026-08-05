#include <cstdio>
#include <memory>
#include <stdexcept>

struct FileCloser
{
    void operator()(std::FILE* file) const noexcept
    {
        if (file != nullptr)
        {
            std::fclose(file);
        }
    }
};

using FilePointer =
    std::unique_ptr<std::FILE, FileCloser>;

FilePointer OpenFile(
    const char* fileName,
    const char* mode
)
{
    std::FILE* file = std::fopen(fileName, mode);

    if (file == nullptr)
    {
        throw std::runtime_error("파일 열기 실패");
    }

    return FilePointer(file);
}

int main()
{
    FilePointer file =
        OpenFile("chapter07_custom_deleter.txt", "w");

    std::fputs("save data\n", file.get());
}
