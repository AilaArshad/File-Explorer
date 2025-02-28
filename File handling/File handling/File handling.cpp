#include "BST.h"

using namespace std;

int main() {
    BST directoryTree;
    string input;

    while (true) {
        cout << "\nEnter command (cr, cd, open, free, dir, history, exit): ";
        getline(cin, input);
        if (input == "exit") {
            break;
        }

        directoryTree.executeCommand(input);
    }

    return 0;
}
