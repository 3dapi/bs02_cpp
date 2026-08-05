#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::vector<int> scores{70, 95, 80, 60};
    std::list<int> levels{3, 1, 4, 2};

    std::sort(scores.begin(), scores.end());
    levels.sort();

    for (int score : scores)
    {
        std::cout << score << ' ';
    }

    std::cout << '\n';

    for (int level : levels)
    {
        std::cout << level << ' ';
    }

    std::cout << '\n';
}
