#include <chrono>
#include <filesystem>
#include <iostream>
#include <random>
#include <sstream>

int main()
{
    std::ostringstream output;
    output << "value=" << 42;

    std::mt19937 engine{1234};
    std::uniform_int_distribution<int> dice{1, 6};

    const auto now = std::chrono::steady_clock::now();
    const std::filesystem::path path = "data" / std::filesystem::path{"player.txt"};

    std::cout << output.str() << '\n';
    std::cout << dice(engine) << '\n';
    std::cout << path << '\n';
    std::cout << (now.time_since_epoch().count() != 0) << '\n';
}
