#include <iostream>

void reverseArray(int* arr, int len){
    int* start = arr;
    int* end = arr + len - 1;

    while(end > start) {
        *start = *start + *end;
        *end = *start - *end;
        *start = *start - *end;
        start++;
        end--;
    }
}

int main() {
    int arr[] { 1, 2, 3, 4, 5};
    std::cout << "Original : ";
    for(int i=0 ; i<5 ; i++)
        std::cout << arr[i] << ", ";
    std::cout << std::endl;
    
    reverseArray(arr, 5);
    std::cout << "Reversed : ";
    for(int i=0 ; i<5 ; i++)
        std::cout << arr[i] << ", ";
    std::cout << std::endl;
}
