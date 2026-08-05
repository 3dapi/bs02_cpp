#include <algorithm>
#include <iostream>
#include <vector>

class RunningTotal
{
public:
    void operator()(int value)
    {
        total += value;
    }

    int GetTotal() const
    {
        return total;
    }

private:
    int total = 0;
};

int main()
{
    std::vector<int> values{10, 20, 30};

    RunningTotal result = std::for_each(
        values.begin(),
        values.end(),
        RunningTotal{});

    std::cout << result.GetTotal() << '\n';
}
