#include <iostream>
#include <string>

int PromptInt(int min, int max)
{
    int s;
    do
    {
        std::cout << "\nPlease enter a valid number: ";
        std::cin >> s;
    } while (s < min || s > max);
    return s;
}

void InputStr(std::string *str1)
{
    std::cin >> *str1;
}
