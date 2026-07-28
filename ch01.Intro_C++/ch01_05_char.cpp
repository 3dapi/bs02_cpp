#include <iostream>
#include <iomanip> // std::hex, std::showbase 사용.
using namespace std;

int main()
{
    char asciiCharacter = 'A';
    wchar_t wideCharacter = L'A';
    char8_t utf8Character = u8'A';
    char16_t utf16Character = u'A';
    char32_t utf32Character = U'A';

	// char8_t, char16_t, char32_t는 std::cout으로 직접 출력할 수 없음.
    // 정수형으로 형 변환(static_cast)하여 값 출력

    cout << hex << showbase; // 16진수 형태로 출력 (0x 접두사 포함)
	
    cout  << "char asciiCharacter     => " << asciiCharacter                            << '\n';
    wcout << "wchar_t wideCharacter   => " << wideCharacter                             << L'\n';
    cout  << "char8_t utf8Character   => " << static_cast<unsigned int>(utf8Character)  << '\n';
    cout  << "char16_t utf16Character => " << static_cast<unsigned int>(utf16Character) << '\n';
    cout  << "char32_t utf32Character => " << static_cast<unsigned int>(utf32Character) << '\n';
}