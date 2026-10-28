#include <iostream>

using namespace std;

int main(){

    int sum = 0;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <=4 ; j++){
            sum += (i + j);
        }
    }
    cout << sum << endl;

    int prod = 0;

    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= i; j++){
            prod += (j*j);
        }
    }
    cout << prod << endl;


}