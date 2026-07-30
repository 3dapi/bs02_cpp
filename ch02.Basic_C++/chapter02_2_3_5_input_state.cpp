#include <iostream>

int main()
{
    int value = 0;
    if (std::cin >> value)
        std::cout << value << '\n';
    else
        std::cout << "정수를 입력하지 않았습니다.\n";
}
