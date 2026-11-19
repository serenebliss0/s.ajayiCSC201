#include <iostream>

using namespace std;

template <size_t N>
int linearSearch(const int (*list)[N], int key){
    for (int i = 0; i < N; i++){
        if (key == (*list)[i])
            return i;
    };

    return -1; //value not found
}



int main(){
    int list[] = {1, 4, 4, 2, 5, -3, 6, 2};

    int i = linearSearch(&list, 4);
    int j = linearSearch(&list, -4);
    int k = linearSearch(&list, -3);

    cout << "Locations of 4, -4, and -3 are " << i << ", " << j << ", and " << k;

}

