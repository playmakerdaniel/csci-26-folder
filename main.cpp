#include <iostream>
#include <vector>

using namespace std;

vector<int> MysteryAlgorithm(vector<int>& sequence, int p) {
    int i = 0;
    int j = sequence.size() - 1;

    while (i < j) {
        while (i < j && sequence[i] < p)
            i++;
        while (i < j && sequence[j] >= p)
            j--;
        if (i < j) {
            swap(sequence[i], sequence[j]);
        }
    }
    return sequence;
}

int main() {
    int n, p;
    cout << "Enter the length of the sequence: ";
    cin >> n;

    vector<int> sequence(n);

    cout << "Enter the number p: ";
    cin >> p;

    cout << "Enter the sequence of numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    vector<int> result = MysteryAlgorithm(sequence, p);

    cout << "Modified sequence:\n";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
