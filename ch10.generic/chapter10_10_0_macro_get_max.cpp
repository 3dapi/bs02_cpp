#include <iostream>

#define GET_MAX(left, right) ((left) < (right) ? (right) : (left))

int main()
{
    int maxCount = GET_MAX(10, 20);
    double maxSpeed = GET_MAX(3.5, 7.2);

    int value = 10;
    int result = GET_MAX(value++, 20);

    std::cout << maxCount << '\n';
    std::cout << maxSpeed << '\n';
    std::cout << result << ", " << value << '\n';
}
