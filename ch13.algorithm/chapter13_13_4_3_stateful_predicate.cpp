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
    std::vector<int> values{10, 25, 40, 5};

    int count = std::count_if(
        values.begin(),
        values.end(),
        IsGreaterThan{20});

    std::cout << count << '\n';
}
