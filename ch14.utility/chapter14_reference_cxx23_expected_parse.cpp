#include <expected>
#include <iostream>
#include <limits>
#include <string_view>


enum class ParseError
{
    Empty,
    InvalidCharacter,
    OutOfRange
};

std::expected<int, ParseError> ParsePositiveInt(std::string_view text)
{
    if (text.empty())
    {
        return std::unexpected(ParseError::Empty);
    }

    int value = 0;

    for (char character : text)
    {
        if (character < '0' || character > '9')
        {
            return std::unexpected(ParseError::InvalidCharacter);
        }

        int digit = character - '0';

        if (value > (std::numeric_limits<int>::max() - digit) / 10)
        {
            return std::unexpected(ParseError::OutOfRange);
        }

        value = value * 10 + digit;
    }

    return value;
}

int main()
{
    auto result = ParsePositiveInt("120");

    if (result)
    {
        std::cout << *result << '\n';
    }

    auto invalid = ParsePositiveInt("12A");

    if (!invalid)
    {
        std::cout << static_cast<int>(invalid.error()) << '\n';
    }
}
