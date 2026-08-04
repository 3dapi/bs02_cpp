#include <chrono>
#include <iostream>

int main()
{
    using Seconds = std::chrono::duration<double>;

    Seconds elapsed{0.016};
    std::cout << elapsed.count() << " s\n";
}
