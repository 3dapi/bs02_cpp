#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> scores{ 75, 90, 60, 85, 100 };

    std::sort(scores.begin(), scores.end());

    int total{};

    std::cout << "정렬된 점수: ";

    for (int score : scores)
    {
        std::cout << score << ' ';
        total += score;
    }

    double average{
        static_cast<double>(total) / static_cast<double>(scores.size())
    };

    std::cout << "\n최대값: " << scores.front() << '\n';
    std::cout << "최소값: " << scores.back() << '\n';
    std::cout << "평균: " << average << '\n';
}
