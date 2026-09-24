#include <iostream>

using namespace std;

int main(){
    cout << "Enter an integer" << endl;

    int userNumber = 0;
    cin >> userNumber;

    if (userNumber % 5 ==0)
        cout << "HiFive\n";

    if (userNumber % 2 == 0)
        cout << "HiEven\n";
}