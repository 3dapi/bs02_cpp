#include <iostream>

class ScopeTrace
{
public:
    ScopeTrace()
    {
        std::cout << "자원 획득\n";
    }

    ~ScopeTrace()
    {
        std::cout << "자원 해제\n";
    }
};

bool SavePlayer(bool valid)
{
    ScopeTrace trace;

    if (!valid)
    {
        return false;
    }

    return true;
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << SavePlayer(false) << '\n';
}
