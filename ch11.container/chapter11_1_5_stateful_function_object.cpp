#include <algorithm>
#include <iostream>
#include <vector>

class IsGreaterThan
{
public:
    explicit IsGreaterThan(int limit)
        : limit(limit)
    {
    }

    bool operator()(int value) const
    {
        return value > limit;
    }

private:
    int limit;
};

int main()
{
    std::vector<int> values{5, 1, 9, 3};

    int count = static_cast<int>(std::count_if(
        values.begin(),
        values.end(),
        IsGreaterThan(3)));

    std::cout << count << '\n';
}
