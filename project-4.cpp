#include <iostream>
#include <vector>
#include <algorithm>

// Function prototype
bool nextPermutation(std::vector<int>& array);
void displayArray(const std::vector<int>& array);

// Main function
int main() {
    std::vector<std::vector<int>> permutations = {
        {1, 2, 3, 4, 5, 6, 7}, // (a)
        {7, 6, 5, 4, 3, 2, 1}, // (b)
        {1, 7, 6, 4, 2, 3, 5}, // (c)
        {3, 7, 6, 5, 4, 2, 1}, // (d)
        {5, 4, 7, 6, 3, 2, 1}  // (e)
    };

    for (auto& perm : permutations) {
        std::cout << "Current permutation: ";
        displayArray(perm);
        if (nextPermutation(perm)) {
            std::cout << "Next permutation: ";
            displayArray(perm);
        } else {
            std::cout << "No next permutation (last in lexicographic order).\n";
        }
        std::cout << std::endl;
    }

    return 0;
}

// Function to display the array
void displayArray(const std::vector<int>& array) {
    for (int elem : array) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Function to generate the next permutation
bool nextPermutation(std::vector<int>& array) {
    // Find the largest index k such that array[k] < array[k + 1]
    int k = -1;
    for (int i = array.size() - 2; i >= 0; --i) {
        if (array[i] < array[i + 1]) {
            k = i;
            break;
        }
    }
    if (k == -1) return false; // Last permutation

    // Find the largest index l greater than k such that array[k] < array[l]
    int l = -1;
    for (int i = array.size() - 1; i > k; --i) {
        if (array[i] > array[k]) {
            l = i;
            break;
        }
    }

    // Swap the value of array[k] with array[l]
    std::swap(array[k], array[l]);

    // Reverse the sequence from array[k + 1] up to and including the final element
    std::reverse(array.begin() + k + 1, array.end());

    return true;
}

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Function prototypes
template <typename T>
bool nextPermutation(std::vector<T>& array);
template <typename T>
void displayArray(const std::vector<T>& array);
template <typename T>
void readArray(std::vector<T>& array, const std::string& input);
bool isPermutationOf1234567(const std::vector<int>& array);

// Main function
int main() {
    std::cout << "Enter 's' for string input or 'n' for numerical input: ";
    char choice;
    std::cin >> choice;
    std::cin.ignore();  // Ignore newline after reading character

    std::string input;
    std::cout << "Enter the elements of the n-tuple: ";
    std::getline(std::cin, input);

    if (choice == 's') {
        std::vector<char> array;
        readArray(array, input);
        if (nextPermutation(array)) {
            displayArray(array);
        } else {
            std::cout << "No next permutation.\n";
        }
    } else if (choice == 'n') {
        std::vector<int> array;
        readArray(array, input);

        if (!isPermutationOf1234567(array)) {
            std::cout << "Error: Input is not a permutation of {1, 2, 3, 4, 5, 6, 7}.\n";
            return 1;
        }

        if (nextPermutation(array)) {
            displayArray(array);
        } else {
            std::cout << "No next permutation (last in lexicographic order).\n";
        }
    } else {
        std::cout << "Invalid input type. Please restart the program.\n";
    }

    return 0;
}

// Function to read array from user input
template <typename T>
void readArray(std::vector<T>& array, const std::string& input) {
    std::istringstream iss(input);
    T element;
    while (iss >> element) {
        array.push_back(element);
    }
}

// Function to display the array
template <typename T>
void displayArray(const std::vector<T>& array) {
    for (const auto& elem : array) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Function to check if the input is a permutation of {1, 2, 3, 4, 5, 6, 7}
bool isPermutationOf1234567(const std::vector<int>& array) {
    if (array.size() != 7) return false;
    std::vector<bool> seen(7, false);
    for (int num : array) {
        if (num < 1 || num > 7 || seen[num - 1]) return false;
        seen[num - 1] = true;
    }
    return true;
}

// [Function to generate the next permutation goes here, same as previous]
