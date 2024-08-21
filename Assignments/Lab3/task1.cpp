#include <iostream>

int main() 
{
    int n;

    std::cout << "Enter the number of rows : ";
    std::cin >> n;

    // Print the upper half of the diamond
    for (int i = 0; i < n; ++i) 
    {
        // leading spaces
        for (int j = 0; j < n - i - 1; ++j) 
            std::cout << " ";

        // stars
        for (int j = 0; j < 2 * i + 1; ++j)
            std::cout << "*";

        std::cout << std::endl;
    }
    
    // Print the lower half of the diamond
    for (int i = n - 2; i >= 0; --i) 
    {
        // leading spaces
        for (int j = 0; j < n - i - 1; ++j)
            std::cout << " ";
        
        // stars
        for (int j = 0; j < 2 * i + 1; ++j)
            std::cout << "*";
        
        std::cout << std::endl;
    }

    return 0;
}
