#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int range = 1000;
    int count =10;
    while(count--)
    {
        int rnd = std::rand() % (range + 1);
        cout << "random: " << rnd << '\n';
    }
}
