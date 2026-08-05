#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main()
{
    std::vector<float> source{1.0f, 2.0f, 3.0f, 4.0f};
    std::vector<float> destination(source.size());

    std::transform(
        std::execution::par,
        source.begin(),
        source.end(),
        destination.begin(),
        [](float value)
        {
            return value * value;
        });

    std::cout << destination.back() << '\n';
}
