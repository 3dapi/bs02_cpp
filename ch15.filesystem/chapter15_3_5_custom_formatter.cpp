#include <format>
#include <iostream>
#include <string>

struct Vector2
{
    float x, y;
};

template <>
struct std::formatter<Vector2>
{
    constexpr auto parse(std::format_parse_context& context)
    {
        return context.begin();
    }

    auto format(
        const Vector2& value,
        std::format_context& context) const
    {
        return std::format_to(
            context.out(),
            "({}, {})",
            value.x,
            value.y);
    }
};

int main()
{
    Vector2 position{10.5f, 20.0f};
    std::string text = std::format("Position: {}", position);
    std::cout << text << '\n';
}
