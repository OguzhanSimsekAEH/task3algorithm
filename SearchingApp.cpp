#include "Searching.cpp"
#include <iostream>
#include <vector>
#include <array>

int main() {
    std::vector<int> vec = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;
    int index = binarySearchFirst(vec, target);
    std::cout << "First occurrence of " << target << " in vector: " << index << std::endl;

    std::array<int, 7> arr = {1, 2, 2, 2, 3, 4, 5};
    index = binarySearchFirst(arr, target);
    std::cout << "First occurrence of " << target << " in array: " << index << std::endl;

    return 0;
}
