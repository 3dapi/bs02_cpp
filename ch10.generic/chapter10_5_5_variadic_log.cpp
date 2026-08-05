#include <iostream>
#include <string_view>

enum class LogLevel
{
    Info,
    Warning,
    Error
};

std::string_view ToString(LogLevel level)
{
    switch (level)
    {
    case LogLevel::Info:
        return "INFO";

    case LogLevel::Warning:
        return "WARNING";

    case LogLevel::Error:
        return "ERROR";
    }

    return "UNKNOWN";
}

template <typename... Args>
void Log(LogLevel level, const Args&... args)
{
    std::cout << '[' << ToString(level) << "] ";
    ((std::cout << args), ...);
    std::cout << '\n';
}

int main()
{
    Log(LogLevel::Info, "Player hp=", 100);
    Log(LogLevel::Warning, "Low stamina: ", 12.5f, '%');
    Log(LogLevel::Error, "Cannot open file: ", "save.dat");
}
