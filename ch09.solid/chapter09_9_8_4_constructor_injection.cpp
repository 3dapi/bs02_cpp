#include <algorithm>
#include <iostream>
#include <string_view>

class IRandomSource
{
public:
    virtual ~IRandomSource() = default;
    virtual int NextInt(int min, int max) = 0;
};

class FixedRandomSource : public IRandomSource
{
public:
    explicit FixedRandomSource(int value)
        : value(value)
    {
    }

    int NextInt(int min, int max) override
    {
        return std::clamp(value, min, max);
    }

private:
    int value;
};

class ICombatLog
{
public:
    virtual ~ICombatLog() = default;
    virtual void Write(std::string_view message) = 0;
};

class ConsoleCombatLog : public ICombatLog
{
public:
    void Write(std::string_view message) override
    {
        std::cout << message << '\n';
    }
};

class CombatService
{
public:
    CombatService(IRandomSource& randomSource,
                  ICombatLog& combatLog)
        : randomSource(randomSource),
          combatLog(combatLog)
    {
    }

    void Run()
    {
        const int value = randomSource.NextInt(1, 100);
        combatLog.Write(value <= 20 ? "critical" : "normal");
    }

private:
    IRandomSource& randomSource;
    ICombatLog& combatLog;
};

int main()
{
    FixedRandomSource randomSource(10);
    ConsoleCombatLog combatLog;
    CombatService combatService(randomSource, combatLog);

    combatService.Run();
}
