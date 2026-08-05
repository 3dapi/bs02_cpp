#include <iostream>

int main()
{
    int count{};
    double speed{};
    bool alive{};
    int* pointer{};
    std::cout << count << ' ' << speed << ' ' << alive << ' ' << (pointer == nullptr) << '\n';
}
