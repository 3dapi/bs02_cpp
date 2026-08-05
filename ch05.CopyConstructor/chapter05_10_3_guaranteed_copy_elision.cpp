#include <iostream>

class Result
{
public:
    Result() = default;

    Result(const Result&) = delete;
    Result(Result&&) = delete;

    bool IsValid() const
    {
        return true;
    }
};

Result CreateResult()
{
    return Result();
}

int main()
{
    Result result = CreateResult();
    std::cout << std::boolalpha << result.IsValid() << '\n';
}
