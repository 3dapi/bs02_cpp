#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> values{1, 2, 3, 4, 5, 6};

    auto result = values
        | std::views::filter([](int value)
          {
              return value % 2 == 0;
          })
        | std::views::transform([](int value)
          {
              return value * value;
          });

    std::vector<int> copied;
    std::ranges::copy(result, std::back_inserter(copied));

    for (int value : copied)
    {
        std::cout << value << ' ';
    }
}
