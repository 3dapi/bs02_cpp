#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

// IsGreaterThan 클래스 정의.
class IsGreaterThan
{
public:
    explicit IsGreaterThan(int limit): limit(limit)
    {
    }
    // 함수 호출 연산자.
    bool operator()(int value) const
    {
        return value > limit;
    }
private:
    int limit;
};

bool IsLessThan(int value, int limit)
{
    return value < limit;
}

int main()
{
    std::vector<int> values{10, 25, 40, 5, 7, 30, 60};
    {
        auto predicate = std::bind(IsLessThan, std::placeholders::_1, 20);
        auto count = std::count_if(values.begin(), values.end(), predicate);
        std::cout << count << '\n';
    }
    {
        auto predicate = std::bind(IsGreaterThan{20}, std::placeholders::_1);
        auto count = std::count_if(values.begin(), values.end(), predicate);
        std::cout << count << '\n';
    }
}