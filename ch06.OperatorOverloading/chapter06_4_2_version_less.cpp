#include <iostream>

struct Version
{
    int major = 0;
    int minor = 0;
    int patch = 0;

    bool operator<(const Version& other) const
    {
        if (major != other.major)
        {
            return major < other.major;
        }

        if (minor != other.minor)
        {
            return minor < other.minor;
        }

        return patch < other.patch;
    }
};

int main()
{
    Version first{1, 4, 2};
    Version second{1, 5, 0};

    std::cout << std::boolalpha
              << (first < second) << '\n';
}
