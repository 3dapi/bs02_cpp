#include <iostream>
#include <string_view>
#include <utility>

std::pair<std::string_view, std::string_view> SplitOnce(
    std::string_view text,
    char delimiter)
{
    std::size_t position = text.find(delimiter);

    if (position == std::string_view::npos)
    {
        return {text, {}};
    }

    return {
        text.substr(0, position),
        text.substr(position + 1)
    };
}

int main()
{
    auto [key, value] = SplitOnce("width=1920", '=');
    std::cout << key << ' ' << value << '\n';
}
