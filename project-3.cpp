#include <iostream>
using namespace std;

// Function to implement the Euclidean algorithm to find the gcd of two numbers
int gcd(int x, int y) {
    int r; // remainder

    // Ensure x is always the smaller number
    if (y < x) {
        swap(x, y);
    }

    r = y % x; // Find remainder of y divided by x

    // Continue finding remainder until it becomes 0
    while (r != 0) {
        y = x; // set y to the last non-zero remainder (x)
        x = r; // set x to the current remainder to continue the algorithm
        r = y % x; // find new remainder
    }

    // x is the gcd when r becomes 0
    return x;
}

int main() {
    int x, y;

    // Prompt the user for input
    cout << "Enter two positive integers to find their GCD: ";
    while (!(cin >> x >> y) || x <= 0 || y <= 0) {
        cout << "Invalid input. Please enter positive integers only: ";
        cin.clear(); // clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore wrong input
    }

    // Compute GCD
    int result = gcd(x, y);

    // Display result
    cout << "The GCD of " << x << " and " << y << " is: " << result << endl;

    return 0;
}
