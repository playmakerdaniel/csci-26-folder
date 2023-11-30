// This program demonstrates a Binary Tree with user interaction.
// The user can insert nodes and view the tree in various traversal orders.
// This file acts as the driver for the IntBinaryTree class.

#include <iostream>
#include <limits>
#include "IntBinaryTree.h"
using namespace std;

// Function to display the menu and get user choice
int getMenuChoice()
{
    int choice;
    cout << "\n*** Binary Tree Traversal Program ***\n";
    cout << "1. Insert a node\n";
    cout << "2. Display the tree using inorder traversal\n";
    cout << "3. Display the tree using preorder traversal\n";
    cout << "4. Display the tree using postorder traversal\n";
    cout << "5. Quit\n";
    cout << "Enter your choice: ";
    while (!(cin >> choice) || choice < 1 || choice > 5)
    {
        cout << "Invalid input. Please enter a number between 1 and 5: ";
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
    return choice;
}

int main()
{
    IntBinaryTree tree;
    int choice, value;

    do {
        choice = getMenuChoice();

        switch (choice)
        {
            case 1:
                cout << "Enter value to insert: ";
                // Error-proofing for integer input
                while (!(cin >> value)) {
                    cout << "Invalid input. Please enter an integer: ";
                    cin.clear(); // Clear error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                }
                tree.insertNode(value);
                break;
            case 2:
                cout << "Inorder traversal: " << endl;
                tree.displayInOrder();
                break;
            case 3:
                cout << "Preorder traversal: " << endl;
                tree.displayPreOrder();
                break;
            case 4:
                cout << "Postorder traversal: " << endl;
                tree.displayPostOrder();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}