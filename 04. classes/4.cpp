#include <iostream>
#include <string>

using namespace std;

class GradeBook
{
    public:
        void setCourseName(string name)
        {
            courseName = name;
        }

        string getCourseName() const
        {
            return courseName;
        }

        void displayMessage() const
        {
            cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
        }

    private:
        string courseName;
};

int main()
{
    string nameOfCourse;
    GradeBook myGradeBook;

    cout << "Initial course name is: " << myGradeBook.getCourseName() << endl;

    cout << "\nPlease enter the course name: " << endl;
    getline(cin, nameOfCourse);
    myGradeBook.setCourseName(nameOfCourse);
    cout << endl;

    myGradeBook.displayMessage();


    return 0;
}