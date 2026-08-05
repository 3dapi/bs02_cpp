#include <cassert>
#include <iostream>
#include <random>

int main()
{
    std::mt19937 firstEngine{1234};
    std::mt19937 secondEngine{1234};

    assert(firstEngine() == secondEngine());
    assert(firstEngine() == secondEngine());

    std::cout << "same sequence\n";
}
