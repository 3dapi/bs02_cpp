#include <iostream>

int GetCount()
{
    return 5;
}

int main()
{
    const int maxCount{ 100 };
    const int userCount{ GetCount() };
    int values[maxCount]{};
    std::cout << values[0] << ' ' << userCount << '\n';
}
