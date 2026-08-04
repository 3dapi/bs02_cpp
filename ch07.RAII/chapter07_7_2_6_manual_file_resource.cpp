#include <cstdio>
#include <iostream>

void SaveData()
{
    std::FILE* file = std::fopen("chapter07_manual_file.txt", "w");

    if (file == nullptr)
    {
        std::cerr << "파일 열기 실패\n";
        return;
    }

    std::fputs("Player\n", file);
    std::fclose(file);
}

int main()
{
    SaveData();
}
