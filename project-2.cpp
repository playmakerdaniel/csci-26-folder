#include <iostream>
#include <vector>
#include <fstream>

int binarySearch(const std::vector<int>& arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    std::vector<int> numbers;
    std::cout << "Enter 1 to input numbers from a file or 2 for manual entry: ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        std::string filename;
        std::cout << "Enter the filename: ";
        std::cin >> filename;
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file. Exiting." << std::endl;
            return 1;
        }
        int num;
        while (file >> num) {
            numbers.push_back(num);
        }
        file.close();
    } else if (choice == 2) {
        int n, val;
        std::cout << "Enter the number of values: ";
        std::cin >> n;
        if (n <= 0) {
            std::cerr << "Invalid number of values. Exiting." << std::endl;
            return 1;
        }
        std::cout << "Enter the values:\n";
        for (int i = 0; i < n; i++) {
            std::cin >> val;
            if (std::cin.fail()) {
                std::cerr << "Invalid input. Please enter a number." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                i--;  
                continue;
            }
            numbers.push_back(val);
        }
    } else {
        std::cerr << "Invalid choice. Exiting." << std::endl;
        return 1;
    }

    mergeSort(numbers, 0, numbers.size() - 1);

    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Enter a value to search: ";
    int searchVal;
    std::cin >> searchVal;

    int result = binarySearch(numbers, 0, numbers.size() - 1, searchVal);
    if (result != -1) {
        std::cout << "Value found at index " << result << std::endl;
    } else {
        std::cout << "Value not found." << std::endl;
    }

    return 0;
}