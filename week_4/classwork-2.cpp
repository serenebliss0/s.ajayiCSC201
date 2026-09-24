#include <iostream>

using namespace std;

int main(){
    cout << "How old are you?" << '\n';

    unsigned int age = 0;

    cin >> age;

    (age >= 18) ? cout << "You are an adult" : cout << "You are NOT an adult";
}