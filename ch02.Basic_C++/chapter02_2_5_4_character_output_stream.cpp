#include <iostream>
#include <iterator>

int main()
{
    const char8_t utf8Text[] = u8"가";
    const char16_t utf16Text[] = u"가";
    const char32_t utf32Text[] = U"가";
    std::cout << std::size(utf8Text) - 1 << ' ' << std::size(utf16Text) - 1 << ' ' << std::size(utf32Text) - 1 << '\n';
}
