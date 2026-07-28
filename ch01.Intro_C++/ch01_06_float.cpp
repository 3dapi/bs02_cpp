#include <iostream> // std::cout, std::fixed, std::scientific, std::defaultfloat
#include <iomanip>  // std::setprecision
using namespace std;

int main()
{
    float speed = 3.5f;
    double distance = 1250.75;
    long double extendedPi = 3.1415926535897932384626433832795L;

    double lightSpeed = 2.99792458e8;
    double epsilon = 1.0e-6;
    float smallValue = 1.0e-3f;

    // 출력 정밀도 설정.
    cout << fixed << setprecision(17);

    cout << "float speed               : " << speed      << '\n';
    cout << "double distance           : " << distance   << '\n';
    cout << "long double extendedPi    : " << extendedPi << "\n\n";

    cout << scientific;
    cout << "double lightSpeed         : " << lightSpeed << '\n';
    cout << "double epsilon            : " << epsilon    << '\n';
    cout << "float smallValue          : " << smallValue << '\n';
}
