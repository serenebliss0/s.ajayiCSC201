#include <iostream>
using namespace std;

int main() {
    for (int row = 0; row < 7; row++) {
        for (int col = 0; col < 6; col++) {

            if (row == 0 || row == 3 || row == 6) {
                if (col == 5)
                {
                    continue;
                }
                // Top, middle and bottom bars
                cout << "*";
            }
            else if (col == 0 || col == 5) {
                // Left and right edges
                cout << "*";
            }
            else {
                cout << " ";
            }

        }
        cout << '\n';
    }

    return 0;
}