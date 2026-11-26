#include <iostream>

using namespace std;

class Student{
    public:
        string name = "nothing";
        string department = "null";
        int score = 0;

        void introduce(){
            cout << "My name is " << name << '\n';
            cout << "I'm a " << department << " student\n";
            cout << "I scored " << score << " out of 65 in my final exam\n";
        }

        //constructor
        Student(string name_t, string department_t, int score_t){
            name = name_t;
            department = department_t;
            score = (score >= 0) ? score_t : 0;
            giveBonus(10, score);

        }

    private:
        void giveBonus(int n, int &score){
            score += n;
        }
};


int main(){

    // Student student1; //default constructor
    Student student1 = Student("Semire", "Computer Science", 50); //using constructors
    student1.name = "Semire";
    student1.department = "Computer Science";
    student1.score = 50;
    student1.introduce();

    // Student student2;
    Student student2 = Student("Ajayi", "", 64); //constructor
    student2.name = "Ajayi";
    student2.score = 64;

    student2.introduce();
}