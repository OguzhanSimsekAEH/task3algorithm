#include <array>
#include <vector>
#include <iostream>

// Linear Search for std::array
template<typename T, std::size_t N>
int linearSearch(std::array<T, N> arr, T target) {
    for (std::size_t i = 0; i < N; ++i) {
        if (arr[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

// Linear Search for std::vector
template<typename T>
int linearSearch(std::vector<T> vec, T target) {
    for (std::size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

// Binary Search for std::vector
template<typename T>
int binarySearch(std::vector<T> vec, T target) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid potential overflow
        if (vec[mid] == target) {
            return mid; // Target found
        }
        else if (vec[mid] < target) {
            left = mid + 1; // Search in the right half
        }
        else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

// Binary Search for std::array
template<typename T, std::size_t N>
int binarySearch(std::array<T, N> arr, T target) {
    int left = 0;
    int right = N - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids potential overflow
        if (arr[mid] == target) {
            return mid; // Target found
        }
        else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        }
        else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

// Implement binarySearchFirst for std::vector
template<typename T>
int binarySearchFirst(std::vector<T> vec, T target) {
    int index = binarySearch(vec, target); // Find any occurrence

    if (index == -1) {
        return -1; // Target not found
    }

    // Search for the first occurrence
    while (index > 0 && vec[index - 1] == target) {
        index--; // Move left to find the first occurrence
    }
    return index; // Return the index of the first occurrence
}

// Implement binarySearchFirst for std::array
template<typename T, std::size_t N>
int binarySearchFirst(std::array<T, N> arr, T target) {
    int index = binarySearch(arr, target); // Find any occurrence

    if (index == -1) {
        return -1; // Target not found
    }

    // Search for the first occurrence
    while (index > 0 && arr[index - 1] == target) {
        index--; // Move left to find the first occurrence
    }
    return index; // Return the index of the first occurrence
}

// Main function for testing
int main() {
    std::vector<int> vec = { 10, 20, 30, 30, 30, 40, 50, 60, 70, 70 };
    int target;
    std::cout << "Enter the value of target: ";
    std::cin >> target;


    int index = binarySearch(vec, target);
    if (index != -1) {
        std::cout << "Binary search. Element found at index: " << index << std::endl;
    }
    else {
        std::cout << "Binary search. Element not found in the vector." << std::endl;
    }


    index = binarySearchFirst(vec, target);
    if (index != -1) {
        std::cout << "Binary search (first). Element found at index: " << index << std::endl;
    }
    else {
        std::cout << "Binary search (first). Element not found in the vector." << std::endl;
    }


    index = linearSearch(vec, target);
    if (index != -1) {
        std::cout << "Linear search. Element found at index: " << index << std::endl;
    }
    else {
        std::cout << "Linear search. Element not found in the vector." << std::endl;
    }


    std::array<int, 10> arr = { 10, 20, 30, 30, 30, 40, 50, 60, 70, 70 };
    index = binarySearch(arr, target);
    if (index != -1) {
        std::cout << "Binary search. Element found at index: " << index << std::endl;
    }
    else {
        std::cout << "Binary search. Element not found in the array." << std::endl;
    }

    index = binarySearchFirst(arr, target);
    if (index != -1) {
        std::cout << "Binary search (first). Element found at index: " << index << std::endl;
    }
    else {
        std::cout << "Binary search (first). Element not found in the array." << std::endl;
    }

    index = linearSearch(arr, target);
    if (index != -1) {
        std::cout << "Linear search. Element found at index: " << index << std::endl;
    }
    else {
        std::cout << "Linear search. Element not found in the array." << std::endl;
    }

    return 0;
}
