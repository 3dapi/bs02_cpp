#include <cstdio>
#include <stdexcept>

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
        std::fclose(file);
    }

    void Write(const char* text)
    {
        std::fputs(text, file);
    }

private:
    std::FILE* file = nullptr;
};

void SaveData()
{
    FileHandle file("chapter07_raii_file.txt", "w");

    file.Write("Player\n");
}

int main()
{
    SaveData();
}
