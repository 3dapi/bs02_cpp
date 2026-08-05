#include <iostream>
#include <string>

int main()
{
    std::string name;
    std::cout << "캐릭터 이름: ";
    std::getline(std::cin, name);
    std::cout << "입력한 이름: " << name << '\n';
}
