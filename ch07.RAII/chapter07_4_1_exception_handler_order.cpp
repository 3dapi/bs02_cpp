#include <iostream>
#include <stdexcept>

void LoadGameData(int errorType)
{
    if (errorType == 1)
    {
        throw std::invalid_argument("잘못된 인수");
    }

    if (errorType == 2)
    {
        throw std::runtime_error("실행 오류");
    }
}

int main()
{
    try
    {
        LoadGameData(1);
    }
    catch (const std::invalid_argument& error)
    {
        std::cerr << "잘못된 인수: "
                  << error.what() << '\n';
    }
    catch (const std::runtime_error& error)
    {
        std::cerr << "실행 오류: "
                  << error.what() << '\n';
    }
    catch (const std::exception& error)
    {
        std::cerr << "표준 예외: "
                  << error.what() << '\n';
    }
}
