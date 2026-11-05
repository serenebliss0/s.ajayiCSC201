#include <iostream>
// #include <algorithm>

using namespace std;

inline int findLargestElement(int *array, int size){

    int max = array[0];

    for(int i = 0; i < size; i++){
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

inline int findSmallestIndex(int *array, int size){
    int min = 0;
    
    for(int i = 0; i < size; i++){
            if (array[i] < array[min])
                min = i;
    };

    return min;
}

int main(){
    // int array[8] = {2,3,4,5,1,2,3,0};
    int array[8];

    //collect user input
    int count = 0;
    for(auto &userInput : array){
        cout << "Enter array [" << count++ << "]\n";
        cin >> userInput;
    }

    int size = sizeof(array) / sizeof(array[0]);

    cout << "The largest element is " << findLargestElement(array, size) << '\n';
    cout << "The index of the smallest is " << findSmallestIndex(array, size) << endl;
}