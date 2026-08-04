#include <iostream>
#include <span>

int main()
{
    int values[]{10, 20, 30};

    const std::span<int> fixedView{values};
    fixedView[0] = 100;

    std::span<const int> readOnlyView{values};

    std::cout << fixedView[0] << ' '
              << readOnlyView[1] << '\n';
}
