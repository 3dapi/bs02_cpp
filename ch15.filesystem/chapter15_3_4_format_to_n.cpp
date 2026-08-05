#include <array>
#include <format>
#include <iostream>

int main()
{
    std::array<char, 32> buffer{};

    auto result = std::format_to_n(
        buffer.begin(),
        buffer.size() - 1,
        "Score: {}",
        1500);

    const std::size_t written =
        static_cast<std::size_t>(result.out - buffer.begin());

    buffer[written] = '\0';

    std::cout << buffer.data() << '\n';
    std::cout << "required: " << result.size << '\n';
}
