#include <iostream>
#include <tuple>

int GetValue()
{
    return -1;
}

int GetCommand()
{
    return 1;
}

std::tuple<int, int> GetCommandTuple()
{
    return {2, 4};
}

int main()
{
    if(int value = GetValue(); value > 0)
    {
        std::cout << "양수: " << value << '\n';
    }
    else
    {
        // else 문에서도 사용가능
        std::cout << "0 또는 음수: " << value << '\n';
    }

    // if-else 문의 범위를 value는 여기서 사용할 수 없음
    // std::cout << "value: " << value << '\n';

    switch(int command = GetCommand(); command)
    {
        case 1:
            std::cout << "시작\n";
            break;
        case 2:
            std::cout << "게임 플레이\n";
            break;
        case 3:
            std::cout << "종료\n";
            break;
        default:
            std::cout << "알 수 없는 명령\n";
            break;
    }

    switch(auto command = GetCommandTuple(); std::get<0>(command))
    {
        case 1:
            std::cout << "시작\n";
            break;
        case 2:
            std::cout << "게임 플레이\n";
            break;
        case 3:
            std::cout << "종료\n";
            break;
        default:
            std::cout << "알 수 없는 명령\n";
            break;
    }
}