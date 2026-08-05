#include <iostream>
using namespace std;

class PlayerStats
{
private:
    // 외부의 직접 변경 제한. 클래스의 변경 규칙을 통한 불변식(Invariant) 유지.
    int hp{10}, mp{20}, level{30};
public:
    PlayerStats() = default;
    int GetHp() const { return hp; }
    int GetMp() const { return mp; }
    int GetLevel() const { return level; }
};

int main()
{
    PlayerStats playerStat;
    for(int i = 0; i < 3; ++i)
    {
        // 위험: 접근 제어와 캡슐화 우회
        // 객체 시작 주소를 int*로 강제 변환. 포인터 연산으로 객체 내부 메모리에 직접 접근.
        int* data = (int*)&playerStat + i;

        // 위험: 객체의 불변식 파괴. private 접근 제어 우회
        // 상태 변경 규칙을 거치지 않고 값 변경. 객체를 int 배열처럼 가정한 접근
        // Undefined Behavior 발생 가능.
        *data = 100 + i * i + i * 500;
    }

    cout << "invalid_private" << '\n';
    // 강제 메모리 변경 이후의 객체 상태 확인
    cout << "HP   : " << playerStat.GetHp() << '\n';
    cout << "MP   : " << playerStat.GetMp() << '\n';
    cout << "Level: " << playerStat.GetLevel() << '\n';
}
