#include <iostream>
#include <string>

class Profile
{
public:
    const std::string& GetName() const
    {
        return name;
    }

    bool Rename(const std::string& newName)
    {
        if (newName.empty())
        {
            return false;
        }

        name = newName;
        return true;
    }

private:
    std::string name;
};

int main()
{
    Profile profile;

    profile.Rename("Player");
    std::cout << profile.GetName() << '\n';
}
