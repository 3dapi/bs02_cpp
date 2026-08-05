#include <chrono>
#include <iostream>

int main()
{
    using namespace std::chrono;

    milliseconds value{2500};
    seconds wholeSeconds = duration_cast<seconds>(value);
    auto down = floor<seconds>(value);
    auto up = ceil<seconds>(value);
    auto nearest = round<seconds>(value);
    duration<double> secondsValue = value;

    std::cout << wholeSeconds.count() << ' '
              << down.count() << ' '
              << up.count() << ' '
              << nearest.count() << ' '
              << secondsValue.count() << '\n';
}
