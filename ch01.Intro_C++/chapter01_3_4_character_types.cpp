#include <iostream>

int main()
{
    char asciiCharacter = 'A';
    wchar_t wideCharacter = L'A';
    char8_t utf8Character = u8'A';
    char16_t utf16Character = u'A';
    char32_t utf32Character = U'A';

    std::cout << asciiCharacter << '\n';
    std::cout << sizeof(wideCharacter) << '\n';
    std::cout << sizeof(utf8Character) << '\n';
    std::cout << sizeof(utf16Character) << '\n';
    std::cout << sizeof(utf32Character) << '\n';
}
