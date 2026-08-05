#include <iostream>
#include <string>
#include <unordered_map>

class IntMap
{
public:
    int& operator[](const std::string& key)
    {
        return values[key];
    }

private:
    std::unordered_map<std::string, int> values;
};

int main()
{
    IntMap map;

    map["score"] = 100;
    map["level"] = 5;

    std::cout << map["score"] << '\n';
    std::cout << map["level"] << '\n';
}
