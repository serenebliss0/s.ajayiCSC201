#include <iostream>

using namespace std;

void printArray(int *array, int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << '\n';
    }
}

template <size_t N>
void printArrayTemplate(int (&array)[N]) {
    for (int element : array) {
        cout << element << "     ";
    }
}

int main(){
    int array[] = {2,3,4,5,6,7,8,10,11};
    int size = sizeof(array) / sizeof(array[0]);

    printArray(array, size);
    printArrayTemplate(array);
}