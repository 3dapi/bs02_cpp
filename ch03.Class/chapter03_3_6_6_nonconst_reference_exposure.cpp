#include <iostream>
#include <string>

class Profile
{
public:
    std::string& GetName()
    {
        return name;
    }

private:
    std::string name;
};

int main()
{
    Profile profile;

    profile.GetName() = "Player";

    std::cout << profile.GetName() << '\n';

    return 0;
}
