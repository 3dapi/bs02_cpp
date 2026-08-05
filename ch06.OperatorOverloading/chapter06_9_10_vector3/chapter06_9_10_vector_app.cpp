#include <iostream>
#include <stdexcept>
#include "Vector3.h"

int main()
{
    Vector3 position(10.0f, 20.0f, 30.0f);
    Vector3 velocity(2.0f, 1.0f, -1.0f);

	auto sizett = sizeof(Vector3);

    Vector3 moved = position + velocity * 3.0f;
    Vector3 reversed = -velocity;

    std::cout << "position: " << position << '\n';
    std::cout << "velocity: " << velocity << '\n';
    std::cout << "moved: " << moved << '\n';
    std::cout << "reversed: " << reversed << '\n';

    moved[1] = 100.0f;
    std::cout << "changed: " << moved << '\n';

    std::cout << std::boolalpha;
    std::cout << "same: " << (position == moved) << '\n';

    float accumulated = 0.0f;
    for (int i = 0; i < 10; ++i)
    {
        accumulated += 0.1f;
    }

    Vector3 calculated(accumulated, 0.0f, 0.0f);
    Vector3 expected(1.0f, 0.0f, 0.0f);

    std::cout << "exact: "
              << (calculated == expected) << '\n';
    std::cout << "nearly: "
              << calculated.NearlyEquals(expected) << '\n';

    try
    {
        std::cout << moved.At(3) << '\n';
    }
    catch (const std::out_of_range& error)
    {
        std::cout << error.what() << '\n';
    }

    Vector3 input;

    std::cout << "x y z 입력: ";
    if (std::cin >> input)
    {
        std::cout << "input: " << input << '\n';
    }
}

// 결과: 입력으로 1 2 3을 전달한 실행 결과의 예
// position: (10, 20, 30)
// velocity: (2, 1, -1)
// moved: (16, 23, 27)
// reversed: (-2, -1, 1)
// changed: (16, 100, 27)
// same: false
// exact: false
// nearly: true
// Vector3 index
// x y z 입력: 1 2 3
// input: (1, 2, 3)

