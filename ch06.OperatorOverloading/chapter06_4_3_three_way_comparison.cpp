#include <compare>
#include <iostream>

struct Version
{
    int major = 0;
    int minor = 0;
    int patch = 0;

    std::strong_ordering operator<=>(
        const Version& other
    ) const
    {
        if (major != other.major)
        {
            return major <=> other.major;
        }

        if (minor != other.minor)
        {
            return minor <=> other.minor;
        }

        return patch <=> other.patch;
    }

    bool operator==(const Version& other) const
    {
        return major == other.major
            && minor == other.minor
            && patch == other.patch;
    }
};

int main()
{
    Version first{1, 4, 2};
    Version second{1, 5, 0};

    auto result = first <=> second;

    if (result < 0)
    {
        std::cout << "first가 이전 버전\n";
    }

    std::cout << std::boolalpha;
    std::cout << (first < second) << '\n';
    std::cout << (first > second) << '\n';
}
