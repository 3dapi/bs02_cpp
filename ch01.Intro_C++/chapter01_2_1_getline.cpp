#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;

    cout << "이름을 입력하세요: ";
    getline(cin, name);

    cout << "입력한 이름: " << name << '\n';
}
