#include <iostream>
#include <numbers>
#include <variant>

struct Circle
{
    double radius;
};

struct Rectangle
{
    double width;
    double height;
};

struct Triangle
{
    double base;
    double height;
};

using ShapeValue = std::variant<Circle, Rectangle, Triangle>;

int main()
{
    ShapeValue shape = Circle{2.0};

    double area = std::visit(
        [](const auto& value) -> double
        {
            using T = std::remove_cvref_t<decltype(value)>;

            if constexpr (std::is_same_v<T, Circle>)
            {
                return std::numbers::pi * value.radius * value.radius;
            }
            else if constexpr (std::is_same_v<T, Rectangle>)
            {
                return value.width * value.height;
            }
            else
            {
                return value.base * value.height * 0.5;
            }
        },
        shape);

    std::cout << area << '\n';
}
