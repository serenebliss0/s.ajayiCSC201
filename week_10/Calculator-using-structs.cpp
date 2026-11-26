#include <iostream>

using namespace std;

typedef struct{
    int sum = 0;
    int product = 0;
    int difference = 0;
    int modulo = 0;
} CalculateResults;

CalculateResults calculateWithStruct(int a, int b){
    return {(a + b), (a * b), (a - b), (a % b)};
}

void calculateByReference(int a, int b, int *sum, int *product, int *difference, int *modulo){
    *sum = a + b;
    *product = a * b;
    *difference = a -b;
    *modulo = a % b;
}

int main(){
    int a = 0;
    int b = 0;
    int sum, prod, diff, mod;

    cout << "Enter number a\n";
    cin >> a;

    cout << "Enter number b\n";
    cin >> b;

    cout << '\n';

    //first use struct method

    CalculateResults results = calculateWithStruct(a,b);

    cout << "Using structs\n";
    cout << "Sum: " << results.sum << '\n';
    cout << "Product: " << results.product << '\n'; 
    cout << "Difference: " << results.difference << '\n'; 
    cout << "Modulo: " << results.modulo << '\n';

    //now pass by reference
    calculateByReference(a, b, &sum, &prod, &diff, &mod);

    cout << "\nUsing references\n";
    cout << "Sum: " << sum << '\n';
    cout << "Product: " << prod << '\n';
    cout << "Difference: " << diff << '\n';
    cout << "Modulo: " << mod << '\n';

}