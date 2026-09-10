#include <iostream>
using namespace std;

int main() {
    
    int a = 5;
    int b = 4;

    int temp = a;

    a = b;

    b = temp;

    cout << "a is now " << a << "\n";
    cout << "b is now " << b << "\n";

}