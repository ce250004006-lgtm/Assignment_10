#include <iostream>

using namespace std;
struct Marks {
    float math;
    float science;
    float english;
};


struct Student {
    int rollNo;
    string name;
    Marks marks;
};

int main() {
    Student students[5];
    float averages[5];

    
    cout << "Enter details for 5 students:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Student " << i+1 << " Roll No: ";
        cin >> students[i].rollNo;
        cout << "Student " << i+1 << " Name: ";
        cin >> students[i].name;
        cout << "Enter marks (Math Science English): ";
        cin >> students[i].marks.math >> students[i].marks.science >> students[i].marks.english;

        
        averages[i] = (students[i].marks.math + students[i].marks.science + students[i].marks.english) / 3.0;
    }

    
    
    
    int highest_idx = 0, lowest_idx = 0;
    for (int i = 1; i < 5; i++) {
        if (averages[i] > averages[highest_idx])
            highest_idx = i;
        if (averages[i] < averages[lowest_idx])
            lowest_idx = i;
    }

   
    cout << "\nStudent with highest average marks:\n";
    
    cout << "Roll No: " << students[highest_idx].rollNo << ", Name: " << students[highest_idx].name << ", Average: " << averages[highest_idx] << endl;

    cout << "Student with lowest average marks:\n";
    cout << "Roll No: " << students[lowest_idx].rollNo << ", Name: " << students[lowest_idx].name << ", Average: " << averages[lowest_idx] << endl;

    return 0;
}

