#include <charconv>
#include <iostream>
#include <string_view>
#include <system_error>

int main()
{
    std::string_view text = "1200";
    int value = 0;

    auto result = std::from_chars(
        text.data(),
        text.data() + text.size(),
        value);

    if (result.ec == std::errc{} &&
        result.ptr == text.data() + text.size())
    {
        std::cout << value << '\n';
    }
}
