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
