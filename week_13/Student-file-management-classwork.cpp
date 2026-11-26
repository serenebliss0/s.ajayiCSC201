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

string fileName = "students.txt"; //can change one variable instead of multiple literals

//add
Student addNewStudentRecord(){
    Student student;

    cout << "Enter student name\n";
    cin.ignore();
    getline(cin, student.name);

    cout << "Enter the student's matric number\n";
    cin >> student.matricNumber;

    cout << "What was the student's score?\n";
    cin >> student.score;

    students.push_back(student); //global student vector

    return student;
}

void pushStudentDetailsToFile(Student *student){
    ofstream file(fileName, ios::app);

    if(file.is_open()){
        file << "Student Name: "<< student->name << '\n';
        file << "Matric Number: " << student->matricNumber << '\n';
        file << "Score: " <<student ->score << '\n';
        file << '\n';

        file.close();

        cout << "Student saved successfully\n";
    }
    else{
        cout << "Error opening file!\n";
    }
}

bool doesFileExist(){
    return filesystem::exists(fileName);
}

void checkStudentDetailsFile(){
    if(doesFileExist()){
        ifstream file(fileName);
        string line;

        if(file.is_open()){
            while(getline(file, line)){
                cout << line << '\n';
            }
            file.close();
        }
        else{
            cout << "Student records file does not exist!\nCreate one first and try again...\n";
        }
    }
}

//display

int main(){

    int userChoice = 0;

    do{
    cout << "Choose an option from the menu below\n";
    cout << "1. Add a new student record\n";
    cout << "2. View all student records\n";
    cout << "3. Exit\n";

    cin >> userChoice;

    switch(userChoice){
        case 1: {
            Student student = addNewStudentRecord();
            pushStudentDetailsToFile(&student);
            break;
        }
        case 2: checkStudentDetailsFile(); break;

        case 3: return 0;

        default:
            cout << "Invalid option!\nTry again";
    }
    }
    while(userChoice != 3);
}