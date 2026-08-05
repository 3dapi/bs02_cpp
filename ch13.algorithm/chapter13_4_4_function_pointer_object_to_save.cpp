#include <functional>
#include <iostream>

bool IsEven(int value)
{
    return value % 2 == 0;
}

class IsGreaterThan
{
public:
    explicit IsGreaterThan(int limit) : limit(limit){}
    bool operator()(int value) const
    {
        return value > limit;
    }
private:
    int limit;
};

int main()
{
    std::function<bool(int)> predicate = IsEven;
    std::cout << std::boolalpha
              << predicate(10) << '\n';

    predicate = IsGreaterThan{20};
    std::cout << predicate(30) << '\n';
}