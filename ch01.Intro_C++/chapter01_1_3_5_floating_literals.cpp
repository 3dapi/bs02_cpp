#include <iomanip>
#include <iostream>

int main()
{
    float speed = 3.5f;
    double distance = 1250.75;
    long double extendedPi = 3.1415926535897932384626433832795L;

    std::cout << speed << '\n';
    std::cout << distance << '\n';
    std::cout << std::setprecision(20) << extendedPi << '\n';
}
