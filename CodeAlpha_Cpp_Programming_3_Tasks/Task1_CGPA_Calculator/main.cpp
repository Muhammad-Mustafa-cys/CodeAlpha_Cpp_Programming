#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Course {
    string name;
    string grade;
    double creditHours;
    double gradePoint;
};

// Convert a letter grade into its grade point.
double getGradePoint(const string& grade) {
    if (grade == "A+" || grade == "a+") return 4.0;
    if (grade == "A"  || grade == "a")  return 4.0;
    if (grade == "A-" || grade == "a-") return 3.7;
    if (grade == "B+" || grade == "b+") return 3.3;
    if (grade == "B"  || grade == "b")  return 3.0;
    if (grade == "B-" || grade == "b-") return 2.7;
    if (grade == "C+" || grade == "c+") return 2.3;
    if (grade == "C"  || grade == "c")  return 2.0;
    if (grade == "C-" || grade == "c-") return 1.7;
    if (grade == "D"  || grade == "d")  return 1.0;
    if (grade == "F"  || grade == "f")  return 0.0;
    return -1.0;
}

int main() {
    int semesters;
    cout << "===== CodeAlpha CGPA Calculator =====\n";
    cout << "Enter number of semesters: ";
    cin >> semesters;

    if (semesters <= 0) {
        cout << "Invalid number of semesters.\n";
        return 0;
    }

    double overallQualityPoints = 0.0;
    double overallCredits = 0.0;

    for (int s = 1; s <= semesters; ++s) {
        int courses;
        cout << "\n--- Semester " << s << " ---\n";
        cout << "Enter number of courses: ";
        cin >> courses;

        if (courses <= 0) {
            cout << "Invalid number of courses.\n";
            return 0;
        }

        vector<Course> semesterCourses;
        double semesterQualityPoints = 0.0;
        double semesterCredits = 0.0;

        for (int i = 0; i < courses; ++i) {
            Course c;

            cout << "\nCourse " << i + 1 << " name: ";
            cin >> ws;
            getline(cin, c.name);

            cout << "Grade (A+, A, A-, B+, B, B-, C+, C, C-, D, F): ";
            cin >> c.grade;

            c.gradePoint = getGradePoint(c.grade);
            if (c.gradePoint < 0) {
                cout << "Invalid grade entered.\n";
                return 0;
            }

            cout << "Credit hours: ";
            cin >> c.creditHours;

            if (c.creditHours <= 0) {
                cout << "Credit hours must be greater than 0.\n";
                return 0;
            }

            semesterCredits += c.creditHours;
            semesterQualityPoints += c.gradePoint * c.creditHours;
            semesterCourses.push_back(c);
        }

        double semesterGPA = semesterQualityPoints / semesterCredits;
        overallQualityPoints += semesterQualityPoints;
        overallCredits += semesterCredits;

        cout << fixed << setprecision(2);
        cout << "\nSemester " << s << " Results\n";
        cout << left << setw(25) << "Course"
             << setw(10) << "Grade"
             << setw(15) << "Credits"
             << "Grade Point\n";

        for (const Course& c : semesterCourses) {
            cout << left << setw(25) << c.name
                 << setw(10) << c.grade
                 << setw(15) << c.creditHours
                 << c.gradePoint << '\n';
        }

        cout << "\nSemester GPA: " << semesterGPA << '\n';
    }

    double cgpa = overallQualityPoints / overallCredits;

    cout << "\n====================================\n";
    cout << "Total Credits: " << overallCredits << '\n';
    cout << "Overall CGPA:  " << cgpa << '\n';
    cout << "====================================\n";

    return 0;
}
