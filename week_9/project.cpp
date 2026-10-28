//Oluwasemire Ajayi
//25120111007
//Week 9 Class Project

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

typedef struct{
    string studentName;
    int savingsAmount = 0;
    double averageSavingsAmount = 0.0;
} Students;

typedef enum{
    Excellent,
    Good,
    Needs_Improvement
} SavingsClassification;

//variables for the future report
unsigned long long overallSavings = 0;
unsigned int highestSavings = 0;
string highestSaver;

vector <Students> createStudentVector(){
    vector <Students> students;
    return students;
}

void erasePreviousSession(vector<Students> &student){
    overallSavings = 0;
    highestSavings = 0;
    highestSaver.clear();
    student.clear();
}

void createStudents(int numberOfStudents, int numberOfWeeks, vector <Students> &students){

    //outer for loop- per student
    for (int i = 0; i < numberOfStudents; i++){
        cout << "Enter student " << i + 1 << "'s name\n";
        string studentName;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, studentName);

        students.push_back({studentName});

        cout << "Recordings Saved for " << studentName << '\n';

        cout << "Student " << i + 1 << " " << students[i].studentName << '\n'; 

        //inner for loop- each student's savings
        for(int j = 0; j < numberOfWeeks; j++){
            cout << "Week " << j + 1 << " Savings (NGN): "; 

            int studentSavings;

            //keep going until value is positive
            do{
                cin >> studentSavings;

                //handle invalid inputs
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                    cout << "Invalid input! Please enter a number.\n";
                    continue;
                }

                if(studentSavings < 0){
                    cout << "Value cannot be less than 0. Try again\n";
                }
            }
            while (studentSavings < 0);
            cout << '\n';

            //save student savings amount
            students[i].savingsAmount += studentSavings;

            //calculate and save their average savings
            students[i].averageSavingsAmount = static_cast<double>(students[i].savingsAmount) / numberOfWeeks;
        }

        //caluclate the highest scorer and the total saved among students
        overallSavings += students[i].savingsAmount;
        if (students[i].savingsAmount > highestSavings || highestSaver.empty()) {
            highestSavings = students[i].savingsAmount;
            highestSaver = students[i].studentName;
        }
    }
}

void registerStudent(vector <Students> &studentVector){

    int numberOfStudents = 0;
    int numberOfWeeks = 0;

    do{
    cout << "How many students will be included in this session?\n";
    cin >> numberOfStudents;

    //handle invalid inputs
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
        cout << "Invalid input! Please enter a number.\n";
        continue;
    }

    if(numberOfStudents > 5){
        cout << "Too many students entered. Try again\n";
    }
    else if(numberOfStudents < 1){
        cout << "Too few students entered. Try again\n";
    }
    }
    while(numberOfStudents < 1 || numberOfStudents > 5);

    do{
        cout << "How many weeks will be recorded?\n\n";
        cin >> numberOfWeeks;

        //invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if(numberOfWeeks > 4){
            cout << "Too many weeks entered. Try again\n";
        }
        else if(numberOfWeeks < 1){
            cout << "Too few weeks entered. Try again\n";
        }
    }
    while(numberOfWeeks < 1 || numberOfWeeks > 4);

    //empty vector before creating new students
    erasePreviousSession(studentVector);
    createStudents(numberOfStudents, numberOfWeeks, studentVector);
}

inline SavingsClassification classifySavings(double averageSavings){
    if(averageSavings >= 2000){
        return SavingsClassification::Excellent;
    }
    else if(averageSavings >= 1000 && averageSavings < 2000){
        return SavingsClassification::Good;
    }
    else{
        return SavingsClassification::Needs_Improvement;
    }
}

bool isStudentsEmpty(const vector<Students>& students) {
    return students.empty();
}

void displaySavings(const vector<Students> &students){

    bool isEmpty = isStudentsEmpty(students);

    if(!isEmpty){
    cout << "=========SAVINGS REPORT=========\n";
    
    //header row
    cout << left 
                << setw(20) << "Name" 
                << setw(15)  << "Total(NGN)" 
                << setw(15)  << "Average" 
                << setw(10)  << "Status" 
                << '\n';

    //individual student report
    for (const auto &student: students){
        cout << left
        << setw(20) << student.studentName
        << setw(15) << student.savingsAmount
        << setw(15) << student.averageSavingsAmount
        << setw(10); 

        switch(classifySavings(student.averageSavingsAmount)){
            case Excellent: cout << "Excellent\n"; break;
            case Good: cout << "Good\n"; break;
            case Needs_Improvement: cout << "Needs Improvement\n"; break;
            }
        }

        cout << "--------------------------------\n";
        cout << "Overall Savings: NGN" << overallSavings << '\n';
        cout << "Highest Saver: " << highestSaver << '\n';
        cout << "Highest Savings: " << highestSavings << '\n';
    }    
    else{
        cout << "No savings record available\n";
    }
}

int main(){

    vector <Students> students = createStudentVector(); //create the vector to store students

    unsigned int userChoice = 0;

    while(userChoice != 3){
    cout << "=================================\n";
    cout << "STUDENT SAVINGS MANAGEMENT SYSTEM\n";
    cout << "=================================\n";

    cout << "1. Record Student Savings\n" 
                << "2. Display Savings Summary\n"
                << "3. Exit\n";
    cout << "Enter your choice:  ";
    cin >> userChoice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
        cout << "Invalid input! Please enter a number.\n";
        continue;
    }

    switch(userChoice){
        case 1: registerStudent(students); break;
        case 2: displaySavings(students); break;
        case 3: return 0;

        default:
            cout << "Invalid option! Please try again\n";
    }
    }

    return 0;
}