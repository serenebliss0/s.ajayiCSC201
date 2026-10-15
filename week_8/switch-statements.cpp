#include <iostream>
#include <map>

using namespace std;

typedef enum{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
    Unknown
} Day;

typedef enum{
    Weekday,
    Weekend
} DayType;

struct DayInfo {
    Day name;
    DayType type;
};

map<int, DayInfo> DaysOfWeek = {
    {0, {Day::Sunday, DayType::Weekend}},
    {1, {Day::Monday, DayType::Weekday}},
    {2, {Day::Tuesday, DayType::Weekday}},
    {3, {Day::Wednesday, DayType::Weekday}},
    {4, {Day::Thursday, DayType::Weekday}},
    {5, {Day::Friday, DayType::Weekday}},
    {6, {Day::Saturday, DayType::Weekend}},
    {-1, {Day::Unknown, DayType::Weekend}}
};


string dayNames[] = {
    "Monday", "Tuesday", "Wednesday", "Thursday",
    "Friday", "Saturday", "Sunday", "Unknown"
};

string dayTypes[] = {"Weekday", "Weekend"};

int main(){

    int day;
    Day dayName;
    DayType typeDay;
    
    cout << "Enter a day of the week 0-6\n";
    cin >> day;

    switch (day) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            dayName = DaysOfWeek.at(day).name;
            typeDay = DaysOfWeek.at(day).type;
            break;
    
        default:
            cout << "Invalid day!\n";
            return 1;
    }

    cout << "You entered " << dayNames[day] << '\n';
    cout << dayNames[day] << " is a " << dayTypes[typeDay] << '\n';
    
}