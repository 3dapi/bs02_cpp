#include <cctype>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_set>

struct CaseInsensitiveEqual
{
    bool operator()(std::string_view left, std::string_view right) const
    {
        if (left.size() != right.size())
        {
            return false;
        }

        for (std::size_t index = 0; index < left.size(); ++index)
        {
            unsigned char leftCharacter =
                static_cast<unsigned char>(left[index]);
            unsigned char rightCharacter =
                static_cast<unsigned char>(right[index]);

            if (std::tolower(leftCharacter) !=
                std::tolower(rightCharacter))
            {
                return false;
            }
        }

        return true;
    }
};

struct CaseInsensitiveHash
{
    std::size_t operator()(std::string_view text) const noexcept
    {
        std::size_t result = 0;

        for (unsigned char character : text)
        {
            unsigned char lower = static_cast<unsigned char>(
                std::tolower(character));
            result = result * 131 + lower;
        }

        return result;
    }
};

int main()
{
    using NameSet = std::unordered_set<
        std::string,
        CaseInsensitiveHash,
        CaseInsensitiveEqual>;

    NameSet names;
    names.insert("Potion");
    names.insert("potion");

    std::cout << names.size() << '\n';
}
