#include <algorithm>
#include <cassert>
#include <string>
#include <string_view>
#include <vector>

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

class MemoryCombatLog : public ICombatLog
{
public:
    void Write(std::string_view message) override
    {
        messages.emplace_back(message);
    }

    const std::vector<std::string>& GetMessages() const
    {
        return messages;
    }

private:
    std::vector<std::string> messages;
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

    int CalculateDamage()
    {
        const bool critical = randomSource.NextInt(1, 100) <= 20;
        combatLog.Write(critical ? "critical" : "normal");
        return critical ? 40 : 20;
    }

private:
    IRandomSource& randomSource;
    ICombatLog& combatLog;
};

int main()
{
    FixedRandomSource randomSource(10);
    MemoryCombatLog combatLog;
    CombatService combatService(randomSource, combatLog);

    assert(combatService.CalculateDamage() == 40);
    assert(combatLog.GetMessages().size() == 1);
}
