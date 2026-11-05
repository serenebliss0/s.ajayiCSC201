#include <iostream>
// #include <algorithm>

using namespace std;

int findLargestElement(int *array, int size){
    for(int i = 0; i < size; i++){
        
    }
}

int main(){
    // int array[8] = {2,3,4,5,1,2,3,0};
    int array[8];

    int count = 0;

    for(auto &userInput : array){
        cout << "Enter array [" << count++ << "]\n";
        cin >> userInput;
    }

    int max = array[0];
    int min = 0;

    // std::sort(array, array+8);

    int size = sizeof(array) / sizeof(array[0]);

    for(int i = 0; i < size; i++){
        // array[i] > array[i+1] ? max = array[i+1] : max = array[i];

        if (array[i] > max)
            max = array[i];
        
            if (array[i] < array[min])
                min = i;
    };

    cout << "The largest element is " << max << '\n';
    cout << "The index of the smallest is " << min << endl;
}