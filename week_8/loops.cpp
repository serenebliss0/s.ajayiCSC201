#include <iostream>

using namespace std;

int main(){

    int sum = 0;
    int i = 1;

    while(i <= 5){
        sum += i;
        i++;
    }

    int product = 1;
    int j = 1;

    while(j <= 5){
        product *= j;
        j++;
    }

    cout << "The product is  " << product << " and sum " << sum << '\n';
}