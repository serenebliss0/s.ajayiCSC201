#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

inline int generateRandomNumber(){
    return (rand() % (10-1+1));
}

//8 random numbers
//calls the random number generator for each element
void populateArrays(int *array, int size){
    for (int i = 0; i < size; i++){
        array[i] = generateRandomNumber();
    }
}

//print the array out
template <size_t N>
void printArray(int (&array)[N]) {
    for (int element : array) {
        cout << element << "     ";
    }
}

int main(){
    srand(time(0));

    int useArray[8];

    populateArrays(useArray, 8);
    printArray(useArray);

}