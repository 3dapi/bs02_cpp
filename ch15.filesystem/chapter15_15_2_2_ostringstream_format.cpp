#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::ostringstream output;
    output << std::fixed
           << std::setprecision(2)
           << 12.3456;

    std::string result = output.str();
    std::cout << result << '\n';
}
