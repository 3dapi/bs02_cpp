#include <cstdio>
#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string text = "hello world";
    std::string_view word{text.data(), 5};

    std::cout << word << '\n';

    std::string nullTerminated{word};
    std::printf("%s\n", nullTerminated.c_str());
}
