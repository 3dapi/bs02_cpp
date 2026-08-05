#include <iostream>

namespace
{
    int internalValue = 10;
    void Helper()
    {
        std::cout << internalValue << '\n';
    }
}

int main()
{
    Helper();
}
