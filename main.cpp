#include <iostream>
#include <vector>

std::vector<int> MysteryAlgorithm(std::vector<int>& sequence, int p) {
    int i = 0;
    int j = sequence.size() - 1;

    while (i < j) {
        while (i < j && sequence[i] < p)
            i++;
        while (i < j && sequence[j] >= p)
            j--;
        if (i < j) {
            std::swap(sequence[i], sequence[j]);
        }
    }
    return sequence;
}

int main() {
    int n, p;
    std::cout << "Enter the length of the sequence: ";
    std::cin >> n;

    std::vector<int> sequence(n);

    std::cout << "Enter the number p: ";
    std::cin >> p;

    std::cout << "Enter the sequence of numbers:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    std::vector<int> result = MysteryAlgorithm(sequence, p);

    std::cout << "Modified sequence:\n";
    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}
