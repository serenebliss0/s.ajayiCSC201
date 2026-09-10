#include <iostream>

using namespace std;


int main(){

    int i = 1;
    int j;
    
    j = ++i;

    cout << "i is " << i << " j is " << j << '\n';

    j = i++;

    cout << "i is " << i << " j is " << j << '\n';

    return 0;

}
        
