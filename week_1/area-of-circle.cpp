#include <iostream>

#define PI 3.14159

using namespace std;

int main() {

    cout << "Enter the radius of your circle" << '\n';
    double radius = 0.0;
    cin >> radius;

    double area = PI * radius * radius;

    printf("The area of your circle is %f", area);

    return 0;
}