#include <iostream>

int main()
{
    char8_t a = u8'A';
    char16_t b = u'가';
    char32_t c = U'가';
    std::cout << sizeof(a) << ' ' << sizeof(b) << ' ' << sizeof(c) << '\n';
}
