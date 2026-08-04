#include <iostream>

int totalScore = 0;

int NextId()
{
    static int id = 0;
    return ++id;
}

int main()
{
    totalScore += 100;

    std::cout << "score: " << totalScore << '\n';
    std::cout << "id: " << NextId() << '\n';
    std::cout << "id: " << NextId() << '\n';
}
