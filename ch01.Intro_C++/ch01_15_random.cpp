#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

int main()
{
    std::random_device seed;
    std::mt19937 engine(seed());

    cout << "std::mt19937: [주사위 랜덤]\n";
    std::uniform_int_distribution<int> dice(1, 6);
    for(int count = 0; count < 10; ++count)
    {
        cout << dice(engine) << ' ';
    }
    cout << "\n\n";

    std::mt19937_64 engine64(seed());

    cout << "std::mt19937_64: [0, 99]\n";
    std::uniform_int_distribution<int> percent(0, 99);
    for(int count = 0; count < 10; ++count)
    {
        cout << percent(engine64) << ' ';
    }
    cout << "\n\n";

    cout << "std::mt19937_64: [0.0 , 1.0]\n";
    cout << fixed << setprecision(7);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    for(int count = 0; count < 10; ++count)
    {
        cout << distribution(engine64) << '\n';
    }
    cout << '\n';
}
