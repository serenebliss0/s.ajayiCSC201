#include <iostream>
using namespace std;

int main() {
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= 5; col++) {
            cout << "*";
        }
        cout << "\n";
    }

    for (int row = 5; row >= 1; row++) {
        for (int col = 5; col >= row; col--) {
            cout << "*";
        }
        cout << "\n";
    }
}