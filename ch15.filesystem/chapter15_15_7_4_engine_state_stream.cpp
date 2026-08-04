#include <iostream>
#include <random>
#include <sstream>

int main()
{
    std::mt19937 engine{20260802};
    engine();
    engine();

    std::ostringstream output;
    output << engine;

    const std::uint32_t expected = engine();

    std::istringstream input{output.str()};
    input >> engine;

    std::cout << std::boolalpha
              << (engine() == expected) << '\n';
}
