#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>

using namespace std;

typedef struct{
    string name;
    int matricNumber;
    float score;
} Student;

vector<Student> students;

//add
Student addNewStudentRecord(){
    Student student;

    cout << "Enter student name\n";
    cin >> student.name;

    cout << "Enter the student's matric number\n";
    cin >> student.matricNumber;

    cout << "What was the student's score?\n";
    cin >> student.score;

    students.push_back(student); //global student vector

    return student;
}

void pushStudentDetailsToFile(Student *student){
    ofstream file("students.txt", ios::app);

    if(file.is_open()){
        file << student->name << '\n';
        file << student->matricNumber << '\n';
        file << student ->score << '\n';

        file.close();
    }
    else{
        cout << "Error opening file!\n";
    }
}

bool doesFileExist(){
    return filesystem::exists("students.txt");
}

void checkStudentDetailsFile(){
    if(doesFileExist){
        ifstream file("students.txt");
        string line;

        if(file.is_open()){
            while(getline(file, line)){
                cout << line << '\n';
            }
            file.close();
        }
        else{
            cout << "Student records file does not exist!";
        }
    }
}

//display

int main(){

    cout << "Choose an option from the menu below\n";
    cout << "1. Add a new student record\n";
    cout << "2. View all student records\n";

    int userChoice;

    cin >> userChoice;

    switch(userChoice){
        case 1: addNewStudentRecord(); break;
        case 2: checkStudentDetailsFile(); break;

        default:
            cout << "Invalid option!\n";
    }
}