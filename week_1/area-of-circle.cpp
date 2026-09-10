#include <iostream>

constexpr double PI = 3.1415926536;

using namespace std;

int main() {

    cout << "Enter the radius of your circle" << '\n';
    double radius = 0.0;
    cin >> radius;

    double areaOfCircle = PI * radius * radius;

    printf("The area of your circle is %f", areaOfCircle);

    return 0;
}