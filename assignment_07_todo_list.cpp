#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter task: ";
    getline(cin >> ws, task);
    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}

void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks yet." << endl;
        return;
    }

    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete." << endl;
        return;
    }

    viewTasks(tasks);
    int choice;
    cout << "Enter task number to delete: ";
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(tasks.size())) {
        cout << "Error: Invalid task number." << endl;
        return;
    }

    cout << "Task \"" << tasks[choice - 1] << "\" has been removed." << endl;
    tasks.erase(tasks.begin() + (choice - 1));
}

int main() {
    vector<string> tasks;
    int choice;

    while (true) {
        cout << "============================" << endl;
        cout << "     TO-DO LIST MENU" << endl;
        cout << "============================" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            addTask(tasks);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            deleteTask(tasks);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Error: Invalid choice." << endl;
        }
    }

    return 0;
}

