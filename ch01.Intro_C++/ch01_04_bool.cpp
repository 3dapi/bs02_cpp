#include <iostream>
using namespace std;

int main()
{
    int cStyleRunning = 1;
    bool cppStyleRunning = true;

    bool first  = 0;
    bool second = 10;
    bool third  = -1;
 
    cout << std::boolalpha;    // bool 값을 1,0 대신, true, false 로 출력.

    cout << "C   방식 논리 상태: " << cStyleRunning << '\n';
    cout << "C++ 방식 논리 상태: " << cppStyleRunning << "\n\n";
 
    cout << "first  : " << first   << '\n';
    cout << "second : " << second  << '\n';
    cout << "third  : " << third   << "\n\n";
}
