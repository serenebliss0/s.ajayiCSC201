#include <iostream>
#include <algorithm>

using namespace std;


template <size_t arraySize>
int binarySearch(const int (*array)[arraySize], int value){
    int low = 0;
    int mid;
    int high = arraySize -1;

    while (low <= high){
        mid = low + (high - low) / 2;

        if ((*array)[mid] == value){
            return mid;
        }
        else if ((*array)[mid] < value)
        {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return -1; //value not found
}

int main(){

    int numbers[10];

    int count = 0;
    int userInput;

    // cout << "How many elements do you want?\n";
    // cin >> userInput;

    cout << "Entering 10 numbers...\n";
    for (auto &number : numbers){
        cout << "Enter number at index " << count++ << '\n';
        cin >> number;
    }

    int sizeIncr = (sizeof(numbers) / sizeof(numbers[0])) -1;

    std::sort(numbers, numbers + sizeIncr); //requires sort!!

    int value;
    cout << "What value are you looking for?\n";
    cin >> value;


    int pos = binarySearch(&numbers, value);

    if(pos == -1){
        cout << "Value not found!\n";
    }
    else{
        cout << "The position of " << value << " is " << pos << '\n';
    }
}