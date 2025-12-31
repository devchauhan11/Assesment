#include <iostream>
#include <string>

using namespace std;

class LecturerRecord
{
private:
    string name;
    string subject;
    string course;
    int totalLectures;

public:
    LecturerRecord()
        : name(""), subject(""), course(""), totalLectures(0) {}

    void inputDetails()
    {
        cout << "Lecturer Name: ";
        getline(cin, name);

        cout << "Subject: ";
        getline(cin, subject);

        cout << "Course: ";
        getline(cin, course);

        cout << "Total Lectures: ";
        cin >> totalLectures;
        cin.ignore();
    }

    void printDetails() const
    {
        cout << "\n-----------------------------\n";
        cout << "Name           : " << name << endl;
        cout << "Subject        : " << subject << endl;
        cout << "Course         : " << course << endl;
        cout << "Lectures Taken : " << totalLectures << endl;
        cout << "-----------------------------\n";
    }
};

int main()
{
    const int lecturerCount = 5;
    LecturerRecord lecturerList[lecturerCount];

    cout << "Lecture Management System\n";

    for (int i = 0; i < lecturerCount; i++)
    {
        cout << "\nEnter details for lecturer " << i + 1 << endl;
        lecturerList[i].inputDetails();
    }

    cout << "\nStored Lecturer Information\n";

    for (int i = 0; i < lecturerCount; i++)
    {
        lecturerList[i].printDetails();
    }

    return 0;
}

