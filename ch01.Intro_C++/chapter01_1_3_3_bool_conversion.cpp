#include <iostream>
using namespace std;

int main()
{
    int cStyleRunning = 1;
    bool cppStyleRunning = true;

    bool first = 0;
    bool second = 10;
    bool third = -1;

    cout << std::boolalpha;

    cout << "C   방식 논리 상태: " << cStyleRunning << '\n';
    cout << "C++ 방식 논리 상태: " << cppStyleRunning << "\n\n";

    cout << "first  : " << first << '\n';
    cout << "second : " << second << '\n';
    cout << "third  : " << third << "\n\n";
}
