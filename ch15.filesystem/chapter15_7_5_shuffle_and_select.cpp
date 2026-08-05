#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main()
{
    std::mt19937 engine{1234};
    std::vector<int> cards{1, 2, 3, 4, 5};
    std::shuffle(cards.begin(), cards.end(), engine);

    if (!cards.empty())
    {
        std::uniform_int_distribution<std::size_t> index{
            0,
            cards.size() - 1};

        int& selected = cards[index(engine)];
        std::cout << selected << '\n';
    }
}
