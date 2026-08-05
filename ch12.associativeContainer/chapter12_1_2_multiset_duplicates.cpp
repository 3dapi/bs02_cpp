#include <iostream>
#include <set>

int main()
{
    std::multiset<int> scores;

    scores.insert(80);
    scores.insert(80);
    scores.insert(90);

    std::cout << scores.count(80) << '\n';
}
