#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cout << "Multiplication table\n";

    for (int header= 1; header <= 12; header ++){
        cout << "" << setw(4) << header;
    }
    cout << "\n\t------------------------------\n";


    for(int row = 1; row <= 12; row++){
        // cout << setw(3) << row;
        cout << setw(4) << row << " | ";

        for(int col = 1; col <=12; col++){
            // cout << col << " | ";
            cout << setw(4) << row * col;
        }
        cout << "\n";

    }

}