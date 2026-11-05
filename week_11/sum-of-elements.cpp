#include <iostream>

using namespace std;

int main(){

    double myList[] = {1.9, 0, 2.9, 3.5, 3.4};

    int size = sizeof(myList) / sizeof(myList[0]);
    double sum, average = 0.0;

    for (const auto &num : myList){
        sum += num;
    }

    average = (sum / size);

    cout << "Sum of elements is  " << sum << '\n';
    cout << "Average of elements " << average << '\n';
}