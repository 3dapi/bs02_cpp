#include <iostream>

class ScopeTrace
{
public:
    explicit ScopeTrace(const char* name)
        : name(name)
    {
        std::cout << name << " 획득\n";
    }

    ~ScopeTrace()
    {
        std::cout << name << " 해제\n";
    }

private:
    const char* name;
};

void UpdateGame()
{
    std::cout << "게임 상태 로드\n";

    {
        ScopeTrace log("frame.log");

        std::cout << "프레임 로그 기록\n";
    }

    std::cout << "게임 계속\n";
}

int main()
{
    UpdateGame();
}
