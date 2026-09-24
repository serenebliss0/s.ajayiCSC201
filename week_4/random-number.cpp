#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>


using namespace std;

//modern way
void randomNumber(){
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(10, 100);

    std::cout << dist(gen);
}

void randomWithRand(){
    srand(time(0));
    cout << rand() << '\n';
}

void randomDiffSeed(){
    srand(time(nullptr));
    cout << rand() << '\n';
}


int main(){

    srand(time(0));
    cout << rand() % 91 + 10 << "\n";        // 10-100
    
}