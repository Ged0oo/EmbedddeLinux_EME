#include <iostream>
#include <array>
#include <cctype>

int main() 
{
    std::array<int, 10> nums;

    for (size_t i = 0; i < 9; i++)
    {
        std::cout << "Enter Number " << i << " : ";
        std::cin >> nums[i];
    }

    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = i; j < 9; j++)
        {
            if(nums[j] < nums[i])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    
    std::cout << "Sorted Numbers: ";
    for (const auto& num : nums)
    {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    return 0;
}