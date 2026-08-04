#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string text = "short";
    std::string_view view = text;
    const char* oldAddress = view.data();

    text += " text that may cause reallocation";
    const char* newAddress = text.data();

    std::cout << std::boolalpha
              << (oldAddress == newAddress)
              << '\n';

    // 주소가 달라졌다면 기존 view를 사용하지 않는다.
}
