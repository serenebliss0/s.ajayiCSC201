#include <iostream>
#include <cmath>
using namespace std;

double pythagoras(int a, int b) {

    return sqrt((a*a) + (b*b));
}

int main() {

    cout << "Enter the short side 1 of the triangle\t";
    double side_a  = 0;
    cin >> side_a;

    cout << "Enter the short side 2 of the triangle\t";
    double side_b  = 0;
    cin >> side_b;

    double hypotenuse = pythagoras(side_a, side_b);

    cout << "The hypotenuse is " << hypotenuse << endl;

}