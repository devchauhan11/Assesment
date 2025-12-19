#include <iostream>
#include <string>
using namespace std;

/*
    Class representing Lecturer details
*/
class Lecturer
{
private:
    string lecturer_name;
    string subject_name;
    string course_name;
    int lecture_count;

public:
    /*
        Constructor to assign initial values
    */
    Lecturer()
    {
        lecturer_name = "";
        subject_name = "";
        course_name = "";
        lecture_count = 0;
    }

    /*
        Method to add lecturer details
    */
    void add_lecture_details()
    {
        cout << "Enter Lecturer Name: ";
        getline(cin, lecturer_name);

        cout << "Enter Subject Name: ";
        getline(cin, subject_name);

        cout << "Enter Course Name: ";
        getline(cin, course_name);

        cout << "Enter Number of Lectures: ";
        cin >> lecture_count;
        cin.ignore(); // clear input buffer
    }

    /*
        Method to display lecturer details
    */
    void display_lecture_details() const
    {
        cout << "\n----------------------------------\n";
        cout << "Lecturer Name     : " << lecturer_name << endl;
        cout << "Subject Name      : " << subject_name << endl;
        cout << "Course Name       : " << course_name << endl;
        cout << "No. of Lectures   : " << lecture_count << endl;
        cout << "----------------------------------\n";
    }
};

int main()
{
    const int TOTAL_LECTURERS = 5;
    Lecturer lecturers[TOTAL_LECTURERS];

    cout << "====== Lecture Management System ======\n";

    // Adding details for 5 lecturers
    for (int i = 0; i < TOTAL_LECTURERS; i++)
    {
        cout << "\nEnter details for Lecturer " << i + 1 << endl;
        lecturers[i].add_lecture_details();
    }

    // Displaying lecturer details
    cout << "\n====== Lecturer Records ======\n";
    for (int i = 0; i < TOTAL_LECTURERS; i++)
    {
        lecturers[i].display_lecture_details();
    }

    return 0;
}
