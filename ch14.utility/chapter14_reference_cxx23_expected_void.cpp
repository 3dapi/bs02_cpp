#include <expected>
#include <iostream>

struct Settings
{
    int volume;
};


enum class SaveError
{
    OpenFailed
};

bool CanOpenFile()
{
    return true;
}

void WriteSettings(const Settings& settings)
{
    std::cout << settings.volume << '\n';
}

std::expected<void, SaveError> SaveSettings(const Settings& settings)
{
    if (!CanOpenFile())
    {
        return std::unexpected(SaveError::OpenFailed);
    }

    WriteSettings(settings);
    return {};
}

int main()
{
    Settings settings{80};
    auto result = SaveSettings(settings);

    if (!result)
    {
        std::cout << static_cast<int>(result.error()) << '\n';
    }
}
