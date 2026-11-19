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

    int numbers[] = {2,3,4,5,6,7,8,9,10};
    int sizeIncr = (sizeof(numbers) / sizeof(numbers[0])) -1;

    std::sort(numbers, numbers + sizeIncr); //requires sort!!

    int value = 5;

    int pos = binarySearch(&numbers, value);

    cout << "The position of " << value << " is " << pos << endl;
}