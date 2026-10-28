#include <iostream>

using namespace std;

int main(){

    int m, n;

    cout << "Enter value m\n";
    cin >> m;
    cout << "Enter value n\n";
    cin >> n;

    
    int answer;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            answer += ((i*i) + (2*i*j) + (j*j));
        }
    }

    cout << answer << endl;
}