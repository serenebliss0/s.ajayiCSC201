#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*TODO

Write a C++ program named StudentPerformance.cpp that performs the requirements below. Use only the C++ concepts covered so far in class.
A. Input Requirements
• Student name
• Matric number
• Age
• Test 1 score
• Test 2 score
• Assignment score
• Examination score
• Total school fee
• Percentage of school fee already paid
B. Calculations
1. Continuous Assessment (CA): CA = Test 1 + Test 2 + Assignment
2. Final Score: Final Score = CA + Examination Score
3. Average CA: Average CA = (Test 1 + Test 2 + Assignment) / 3
4. Amount Paid: Amount Paid = School Fee × (Percentage Paid / 100)
5. Outstanding Balance: Balance = School Fee - Amount Paid
*/

//Gather all data here and print formatted result
void printPerformanceReport(
    string studentName,
    string matricNumber,
    unsigned int age,
    double testOneScore,
    double testTwoScore,
    double assignmentScore,
    double continuousAssignmentScore,
    double averageContinuousAssignmentScore,
    double examScore,
    double finalScore,
    double schoolFees,
    double percentagePaid,
    double amountPaid,
    double outstandingFees
){

    cout << "=========================\n";
    cout << "STUDENT PERFORMANCE SYSTEM\t\t" << endl;
    cout << "=========================\n";

    cout << "Name: \t" << studentName << '\n';
    cout << "Matric Number: \t" << matricNumber << '\n';
    cout << "Age: \t\t\t" << age << '\n';
    cout << "Test 1: \t" << testOneScore << '\n';
    cout << "Test 2: \t" << testTwoScore << '\n';
    cout << "Assignment: \t" << assignmentScore << '\n';
    cout << "CA Score: \t" << continuousAssignmentScore << '\n';
    cout << "Average CA: \t" << averageContinuousAssignmentScore << '\n';
    cout << "Exam Score: \t" << examScore << '\n';
    cout << "Final Score: \t" << finalScore << '\n';
    cout << "School Fees: \t" << setprecision(0) << schoolFees << '\n';
    cout << "Percentage Paid: \t" << percentagePaid << '\n';
    cout << "Amount Paid: \t" << setprecision(0) <<  amountPaid << '\n';
    cout << "Outstanding: \t" << outstandingFees << '\n';
    cout << "=========================" << endl;

}


double calculateContinuousAssessment(
    double testOneScore,
    double testTwoScore,
    double assignmentScore
)
{
    return testOneScore + testTwoScore + assignmentScore;
}

double calculateFinalScore(
    double continuousAssessment,
    double examScore
){
    return continuousAssessment + examScore;
}

double calculateAverageContinuousAssessment(
    double testOne,
    double testTwo,
    double assignmentScore
){
    return ((testOne + testTwo + assignmentScore) / 3.0);
}

double calculateAmountPaid(
    double schoolFees,
    double percentagePaid
){
    return schoolFees * (percentagePaid / 100.0);
}

double calculateOutstandingBalance(
    double schoolFees,
    double amountPaid
){
    return schoolFees - amountPaid;
}


int main(){

    //define all variables needed
    string studentName;
    unsigned int age;
    string matricNumber;
    double firstTestScore;
    double secondTestScore;
    double assignmentScore;
    double examScore;
    double totalSchoolFees;
    double percentageAlreadyPaid;
    
    cout << "What is the student's name?" << '\n';
    // cin.ignore();
    getline(cin, studentName);

    cout << "\nEnter the student's matric number\n";
    getline(cin, matricNumber);

    cout << "\nHow old is the student?\n";
    cin >> age;

    cout << "\nWhat did the student score in Test 1?\n";
    cin >> firstTestScore;

    cout << "\nWhat did the student score in Test 2?\n";
    cin >> secondTestScore;

    cout << "\nWhat did the student score in Assignment?\n";
    cin >> assignmentScore;

    cout << "\nWhat did the student score in their Exam?\n";
    cin >> examScore;

    cout << "\nWhat is the student's total school fees?\n";
    cin >> totalSchoolFees;

    cout << "\nHow much has the student paid already (in percentages).\nMake sure to omit the % sign\n";
    cin >> percentageAlreadyPaid;

    //Calculated variables
    double continuousAssignment = calculateContinuousAssessment(firstTestScore, secondTestScore, assignmentScore);
    double finalScore = calculateFinalScore(continuousAssignment, examScore);
    double averageCA= calculateAverageContinuousAssessment(firstTestScore, secondTestScore, assignmentScore);
    double amountPaid = calculateAmountPaid(totalSchoolFees, percentageAlreadyPaid);
    double outstandingBalance = calculateOutstandingBalance(totalSchoolFees, amountPaid);

    printPerformanceReport(
        studentName,
        matricNumber,
        age,
        firstTestScore,
        secondTestScore,
        assignmentScore,
        continuousAssignment,
        averageCA,
        examScore,
        finalScore,
        totalSchoolFees,
        percentageAlreadyPaid,
        amountPaid,
        outstandingBalance        
    );
    
    return 0;

}