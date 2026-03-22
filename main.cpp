#include <iostream>
#include <vector>
#include "src/slide.hpp"

static void printArray(const int arr[], int size) {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

static void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (int i = 0; i < (int)vec.size(); i++) {
        std::cout << vec[i];
        if (i < (int)vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << "=== arrayShift ===\n";
    int arr1[] = {1, 2, 3, 4, 5};
    arrayShift(arr1, 5, 1); printArray(arr1, 5);
    arrayShift(arr1, 5, 1); printArray(arr1, 5);
    arrayShift(arr1, 5, 1); printArray(arr1, 5);

    std::cout << "\n";
    int arr2[] = {1, 2, 3, 4, 5};
    arrayShift(arr2, 5, 3); printArray(arr2, 5);
    arrayShift(arr2, 5, 3); printArray(arr2, 5);
    arrayShift(arr2, 5, 3); printArray(arr2, 5);

    std::cout << "\n";
    int arr3[] = {1, 2, 3};
    arrayShift(arr3, 3, 3); printArray(arr3, 3);
    int arr4[] = {1, 2, 3};
    arrayShift(arr4, 3, 4); printArray(arr4, 3);

    std::cout << "\n=== arrayShiftLeft / arrayShiftRight ===\n";
    int arr5[] = {1, 2, 3, 4, 5};
    arrayShiftLeft (arr5, 5, 2); printArray(arr5, 5);
    arrayShiftRight(arr5, 5, 2); printArray(arr5, 5);
    arrayShiftRight(arr5, 5, 1); printArray(arr5, 5);
    std::cout << "\n=== vectorShift ===\n";
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    vectorShift(v1, 1); printVector(v1);
    vectorShift(v1, 3); printVector(v1);
    vectorShift(v1, 5); printVector(v1);
    return 0;
}
