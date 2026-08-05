#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <utility>

class FileHandle
{
public:
    FileHandle(const char* fileName, const char* mode)
        : file(std::fopen(fileName, mode))
    {
        if (file == nullptr)
        {
            throw std::runtime_error(
                "파일을 열 수 없습니다."
            );
        }
    }

    ~FileHandle()
    {
        Close();
    }

    FileHandle(const FileHandle&) = delete;
    FileHandle& operator=(const FileHandle&) = delete;

    FileHandle(FileHandle&& other) noexcept
        : file(other.file)
    {
        other.file = nullptr;
    }

    FileHandle& operator=(FileHandle&& other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }

        Close();

        file = other.file;
        other.file = nullptr;

        return *this;
    }

    void Write(const char* text)
    {
        if (file == nullptr)
        {
            throw std::logic_error(
                "파일이 열려 있지 않습니다."
            );
        }

        if (std::fputs(text, file) == EOF)
        {
            throw std::runtime_error(
                "파일 쓰기에 실패했습니다."
            );
        }
    }

    bool IsOpen() const
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
    FileHandle first(
        "chapter07_move_file.txt",
        "w"
    );

    first.Write("first\n");

    FileHandle second = std::move(first);

    second.Write("second\n");

    std::cout << std::boolalpha;
    std::cout << first.IsOpen() << '\n';
    std::cout << second.IsOpen() << '\n';
}
