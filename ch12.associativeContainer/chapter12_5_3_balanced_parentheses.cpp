#include <iostream>
#include <stack>
#include <string>

bool IsBalanced(const std::string& text)
{
    std::stack<char> brackets;

    for (char character : text)
    {
        if (character == '(')
        {
            brackets.push(character);
        }
        else if (character == ')')
        {
            if (brackets.empty())
            {
                return false;
            }

            brackets.pop();
        }
    }

    return brackets.empty();
}

int main()
{
    std::cout << std::boolalpha
              << IsBalanced("(a + b) * (c - d)") << '\n'
              << IsBalanced("(a + b))") << '\n';
}
