#include <iostream>

int GetCommand()
{
    return 1;
}

int main()
{
    switch (int command = GetCommand(); command)
    {
    case 1:
        std::cout << "시작\n";
        break;
    case 2:
        std::cout << "종료\n";
        break;
    default:
        std::cout << "알 수 없는 명령\n";
        break;
    }
}
