#include <iostream>
#include <string>
#include <cctype>

int main() 
{
    std::cout << "Enter String : " << std::endl;
    std::string str;
    std::cin >> str;
    std::string result;

    for (char ch : str) 
    {
        if (std::isupper(static_cast<unsigned char>(ch)) && !result.empty()) 
        {
            result += ' ';
        }
        result += ch;
    }

    std::cout << result << std::endl;

    return 0;
}