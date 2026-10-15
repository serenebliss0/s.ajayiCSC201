#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <string>


using namespace std;

int main(){
    srand(time(nullptr));

    int num1 = rand() % (10-1+1) + 0;
    int num2 = rand() % (10-1+1) + 0;

    string userInput;

    do{
        num1 = rand() % (10-1+1) + 0;
        num2 = rand() % (10-1+1) + 0;
    
        if (num1 < num2){
            swap(num1, num2);
        }

        int actualAnswer = num1 - num2;

        
        cout << "What is the value of  " << num1 << " - " << num2 << " ? \n";
        cout << "Press n to stop at any time\n";
        cin >> userInput;

        if(stoi(userInput) == actualAnswer){
            cout << "You are correct\n";
        }
        else if(stoi(userInput) != actualAnswer){
            cout << "You are incorrect\n";
        }
        else if(userInput == "n"){
            return 0;
        }
    }
    while (userInput != "n");

    return 0;
}