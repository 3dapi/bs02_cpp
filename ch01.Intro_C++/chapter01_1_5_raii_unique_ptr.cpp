#include <iostream>
#include <memory>

void ProcessData(bool cancel)
{
    auto values = std::make_unique<int[]>(100);
    values[0] = 10;
    values[1] = 20;

    if (cancel)
    {
        return;
    }

    values[2] = values[0] + values[1];
    std::cout << values[2] << '\n';
}

int main()
{
    ProcessData(false);
}
