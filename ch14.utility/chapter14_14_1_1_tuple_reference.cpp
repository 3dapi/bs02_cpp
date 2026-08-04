#include <iostream>
#include <tuple>

int main()
{
    int score = 100;
    std::tuple<int&, const char*> data{score, "Alice"};

    std::get<0>(data) = 200;

    std::cout << score << ' ' << std::get<1>(data) << '\n';
}
