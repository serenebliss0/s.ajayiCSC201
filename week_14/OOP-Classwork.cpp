#include <iostream>

using namespace std;

class Student{
    private:
        const int MAX_SCORE = 100;
        const int MIN_SCORE = 0;

    public:
        string _name;
        int _score;

        //constructor
        Student(string name_in, int score_in){
            if (!name_in.empty())
                _name = name_in;
            
            _score = (score_in >=MIN_SCORE && score_in <= MAX_SCORE) ? score_in : 0;
        }

        void display(){
            cout << "Student Name: " << _name << '\n';
            cout << "Score: " << _score << '\n';
        }
};

int main(){
    Student student1 = Student("John", 78);
    student1.display();

    return 0;
}