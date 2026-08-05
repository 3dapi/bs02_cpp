#include <iostream>

int main()
{
    using std::cin;
    using std::cout;

    int level = 0;
    double speed = 0.0;

    cout << "레벨과 이동 속도를 입력하세요: ";
    cin >> level >> speed;

    cout << "Level: " << level
         << ", Speed: " << speed << '\n';
}
