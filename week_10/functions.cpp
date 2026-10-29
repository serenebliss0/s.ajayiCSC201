#include <iostream>
#include <limits>
#include <map>

using namespace std;

//prototypes
int max(const int &num1, const int &num2);
double max(const double &num1, const double &num2);

int lengthOfName(const string &name = "Serenity"){
    return name.length();
    // return sizeof(name) / sizeof(name[0]);
}

void calculate(int a, int b, int *product, int *sum){
    *product = a * b;
    *sum = a + b;
}

typedef struct{
    int sum;
    int prod;
} CalculateResult;

CalculateResult calculateButBetter(int a, int b){
    return {(a+b), (a*b)};
}

map<int, int> calculateButMaps(int a, int b) {
    map<int, int> calc;
    calc[0] = a * b;
    calc[1] = a + b;

    return calc;
}

//functions
//name
// params
//rtype
//body

void nPrint(const char ch = '*', const int num = 1){
    for(int i = 0; i < num; i++){
        cout << ch;
    }
}

int main(){
    int num1 = 5;
    int num2 = 5;

    int maxNum = max(num1, num2);

    cout << maxNum << '\n';

    double num3 = 5.005;
    double num4 = 7.0;

    double maxDouble = max(num3, num4);
    cout << maxDouble << '\n';

    // cout << "Enter a character\n";
    // char useChar;
    // cin >> useChar;

    // cout << "How many times will it print?\n";
    // int useCharTimes;
    // cin >> useCharTimes;

    // nPrint(useChar, useCharTimes);
    nPrint(67, 'a');
    cout << sizeof(char);


    // int num = 'a';
    // cout << num;

    cout << numeric_limits<unsigned long long>::max();

    cout << endl;
    cout << '\n';
    cout << lengthOfName();

    {
        cout << "\nsum, prod part\n";
        int sum, prod;
        calculate(12, 8, &prod, &sum);

        cout << sum << '\n';
        cout << prod << '\n';

        cout << calculateButBetter(12,8).sum << '\n';
        cout << calculateButBetter(12,8).prod << '\n';

        map<int, int> result = calculateButMaps(3, 4);

        cout << result[0] << '\n'; // 12
        cout << result[1] << '\n'; // 7
    }
}

//definitions
int max(const int &num1, const int &num2){
    return (num1 > num2) ? num1 : num2;
}

double max(const double &num1, const double &num2){
    return (num1 > num2) ? num1 : num2;
}