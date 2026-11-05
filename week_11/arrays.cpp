#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    float student1 = 30.23;
    float student2 = 12.11;
    float student3 = 02.03;
    float student4 = 10.183;
    float student5 = 42.13;

    float students[5];

    double myList[] = {1.9, 0, 2.9, 3.5, 3.4};
    
    //traversal
    //insert
    //delete
    //search
    //update
    //sorting

    // myList[5] = 6.0;

    for(auto num: myList){
        cout << num << '\n';
    }

    for(auto num: students){
        cout << num << '\n';
    }

    int testArray[10] = {1,2,3};

    for (auto test: testArray){
        cout << test << '\n';
    }

    int size = sizeof(myList) / sizeof(myList[0]);

    for (int i = 0; i <= size; i++){
        cout << myList[i] + 5.0 << "     ";
    }

    cout << '\n';

    cout << max(myList[0], myList[size]);
    
}