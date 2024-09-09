#include <iostream>

int* rotateArray(int* arr, int len, int rotate) {
    int *newArr = new int[len];
    for(int i=0 ; i<len ; i++) {
        newArr[i] = arr[(i+rotate)%len];
    }
    return newArr;
}

int main() {
    int arr[] { 1, 2, 3, 4, 5};
    std::cout << "Original : ";
    for(int i=0 ; i<5 ; i++)
        std::cout << arr[i] << ", ";
    std::cout << std::endl;
    
    int *newArr = rotateArray(arr, 5, 13);
    std::cout << "Rotated : ";
    for(int i=0 ; i<5 ; i++)
        std::cout << newArr[i] << ", ";
    std::cout << std::endl;
}
