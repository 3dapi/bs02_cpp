#include <iostream>
#include <vector>

void ProcessData()
{
    std::vector<int> values(100);
    values[0] = 10;

    std::cout << values[0] << '\n';
}

int main()
{
    ProcessData();
}
