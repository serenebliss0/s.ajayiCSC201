#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    //multiply by 8 to conv to bits!!!
    cout << "char: " << sizeof(char) * 8 << " bits\n";
    cout << "short: " << sizeof(short) * 8 << " bits\n";
    cout << "int: " << sizeof(int) * 8 << " bits\n";
    cout << "long: " << sizeof(long) * 8 << " bits\n";
    cout << "long long: " << sizeof(long long) *8 << " bits\n";
    cout << "float: " << sizeof(float) * 8 << " bits\n";
    cout << "double: " << sizeof(double) * 8 << " bits\n";

    return 0;
}

