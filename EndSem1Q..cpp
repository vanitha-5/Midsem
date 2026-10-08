#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<string> line;
    int choice;
    string name;

    while (true) {

        cout << "\n1. Add Student\n2. Serve Student\n3. Display Line\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter name: ";
            cin >> name;
            line.push(name);
            cout << name << " joined the line.\n";
        }

        else if (choice == 2) {
            if (line.empty()) {
                cout << "The line is empty!\n";
            } else {
                cout << "Serving: " << line.front() << "\n";
                line.pop();
            }
        }


        else if (choice == 3) {
            if (line.empty()) {
                cout << "Nobody is waiting.\n";
            } else {
                cout << "Waiting: ";
                queue<string> temp = line;
                while (!temp.empty()) {
                    cout << temp.front() << " ";
                    temp.pop();
                }
                cout << "\n";
            }
        }

        else if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
