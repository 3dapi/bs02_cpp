#include <iostream>
#include <stdexcept>

void LoadGameData()
{
    throw std::runtime_error("데이터 로드 실패");
}

void LoadWithLog()
{
    try
    {
        LoadGameData();
    }
    catch (const std::exception& error)
    {
        std::cerr << "log: "
                  << error.what() << '\n';

        throw;
    }
}

int main()
{
    try
    {
        LoadWithLog();
    }
    catch (const std::exception& error)
    {
        std::cerr << "main: "
                  << error.what() << '\n';
    }
}
