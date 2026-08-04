#include <iostream>

template <typename T>
T GetMax(T left, T right)
{
    return left < right ? right : left;
}

int main()
{
    int maxCount = GetMax(10, 20);
    double maxSpeed = GetMax(3.5, 7.2);

    std::cout << maxCount << '\n';
    std::cout << maxSpeed << '\n';
}
