#include <iostream>


using namespace std;

// Structure to store Employee data
struct Employee {
    int id;
    string name;
    float salary;
};

int main() {
    Employee employees[10];
    cout << "Enter details for 10 employees (id name salary):\n";
    for (int i = 0; i < 10; i++) {
        cin >> employees[i].id >> employees[i].name >> employees[i].salary;
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display all employee details\n";
        cout << "2. Search for an employee by id\n";
        cout << "3. Increase salary by 10% (salary < 30000)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nEmployee Details:\n";
            for (int i = 0; i < 10; i++) {
                cout << "ID: " << employees[i].id
                     << ", Name: " << employees[i].name
                     << ", Salary: " << employees[i].salary << endl;
            }
        } else if (choice == 2) {
            int searchId, found = 0;
            cout << "Enter employee id to search: ";
            cin >> searchId;
            for (int i = 0; i < 10; i++) {
                if (employees[i].id == searchId) {
                    cout << "ID: " << employees[i].id
                         << ", Name: " << employees[i].name
                         << ", Salary: " << employees[i].salary << endl;
                    found = 1;
                }
            }
            if (!found) cout << "Employee not found.\n";
        } else if (choice == 3) {
            cout << "Increasing salary by 10% for employees earning less than 30000...\n";
            for (int i = 0; i < 10; i++) {
                if (employees[i].salary < 30000) {
                    employees[i].salary = employees[i].salary * 1.10;
                }
            }
            cout << "Updated salaries applied.\n";
        } else if (choice == 4) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
