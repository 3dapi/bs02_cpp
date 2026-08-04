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

void Process()
{
    ScopeTrace trace;

    std::cout << "작업 수행\n";
}

int main()
{
    Process();
}
