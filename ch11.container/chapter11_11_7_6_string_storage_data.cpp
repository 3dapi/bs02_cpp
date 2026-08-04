#include <iostream>
#include <string>

int main()
{
    std::string text = "abc";
    text.reserve(256);

    char* data = text.data();
    data[0] = 'A';

    const char* cText = text.c_str();

    std::cout << text.size() << ' '
              << text.capacity() << ' '
              << cText << '\n';
}
