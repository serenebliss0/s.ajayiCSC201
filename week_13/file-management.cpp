#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    //ofstream - creation and writing data
    //ifstream - reads from existing data
    //fstream - read and write data to file

    ofstream file("student.txt", ios::app);


    if(file.is_open()){
        file << "\nSemire was here\nAnd here too\n";
        file << "Matric number was here\n";
        file << "Score is 100\n";

        file.close();
        cout << "File create successfully\n";
    }
    else{
        cout << "Unable to open file!\n";
    }

    ifstream readFile("student.txt");
    string line;

    if(readFile.is_open()){
        while(getline(readFile, line)){
                cout << line << endl;
        }

        file.close();
    }
    else{
        cout << "File not found\n";
    }
}