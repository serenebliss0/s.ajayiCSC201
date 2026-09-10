#include <iostream>

using namespace std;

constexpr double PI = 3.1415926536;

inline constexpr double square(double x){
    return x * x;
}

int main() {

    cout << "Enter the radius of your circle" << '\n';
    double radius = 0.0;
    cin >> radius;

    double areaOfCircle = PI * square(radius);

    printf("The area of your circle is %f", areaOfCircle);

    return 0;
}