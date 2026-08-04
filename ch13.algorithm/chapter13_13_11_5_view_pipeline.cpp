#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> values{1, 2, 3, 4, 5, 6, 7, 8};

    auto result = values
        | std::views::filter([](int value)
          {
              return value % 2 == 0;
          })
        | std::views::transform([](int value)
          {
              return value * value;
          })
        | std::views::take(3);

    for (int value : result)
    {
        std::cout << value << ' ';
    }
}
