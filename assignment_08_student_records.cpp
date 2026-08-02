#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

void addStudent(vector<Student>& students) {
    Student student;
    int count;

    cout << "Student name: ";
    getline(cin >> ws, student.name);
    cout << "Student ID: ";
    cin >> student.id;
    cout << "How many scores? ";
    cin >> count;

    for (int i = 0; i < count; ++i) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        student.scores.push_back(score);
    }

    students.push_back(student);
    cout << "Student \"" << student.name << "\" added successfully." << endl;
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << left << setw(20) << "Name" << setw(10) << "ID" << "Scores" << "Average" << endl;
    for (const auto& student : students) {
        double sum = 0;
        for (double score : student.scores) {
            sum += score;
        }
        double average = student.scores.empty() ? 0 : sum / student.scores.size();

        cout << left << setw(20) << student.name << setw(10) << student.id;
        for (size_t i = 0; i < student.scores.size(); ++i) {
            if (i > 0) cout << ", ";
            cout << student.scores[i];
        }
        cout << "  " << fixed << setprecision(2) << average << endl;
    }
}

void calculateAverageForStudent(const vector<Student>& students) {
    int targetId;
    cout << "Enter student ID: ";
    cin >> targetId;

    for (const auto& student : students) {
        if (student.id == targetId) {
            double sum = 0;
            for (double score : student.scores) {
                sum += score;
            }
            double average = student.scores.empty() ? 0 : sum / student.scores.size();
            cout << student.name << "'s average score: " << fixed << setprecision(2) << average << endl;
            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "===============================" << endl;
        cout << "   STUDENT RECORD SYSTEM MENU" << endl;
        cout << "===============================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayStudents(students);
        } else if (choice == 3) {
            calculateAverageForStudent(students);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Error: Invalid choice." << endl;
        }
    }

    return 0;
}

