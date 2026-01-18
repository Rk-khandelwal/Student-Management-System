#include <iostream>
#include <cstdlib>
using namespace std;

string arr1[20], arr2[20], arr3[20], arr4[20], arr5[20];
int total = 0;

void enter() {
    int ch;
    cout << "How many students do you want to enter? ";
    cin >> ch;

    for (int i = total; i < total + ch; i++) {
        cout << "\nEnter data of student " << i + 1 << endl;

        cout << "Enter Name: ";
        cin >> arr1[i];

        cout << "Enter Roll No: ";
        cin >> arr2[i];

        cout << "Enter Course: ";
        cin >> arr3[i];

        cout << "Enter Class: ";
        cin >> arr4[i];

        cout << "Enter Contact: ";
        cin >> arr5[i];
    }

    total += ch;
}

void show() {
    if (total == 0) {
        cout << "\nNo data is entered\n";
    } else {
        for (int i = 0; i < total; i++) {
            cout << "\nData of Student " << i + 1 << endl;
            cout << "Name: " << arr1[i] << endl;
            cout << "Roll No: " << arr2[i] << endl;
            cout << "Course: " << arr3[i] << endl;
            cout << "Class: " << arr4[i] << endl;
            cout << "Contact: " << arr5[i] << endl;
        }
    }
}

void search() {
    if (total == 0) {
        cout << "\nNo data is entered\n";
        return;
    }

    string rollno;
    cout << "Enter Roll No to search: ";
    cin >> rollno;

    for (int i = 0; i < total; i++) {
        if (rollno == arr2[i]) {
            cout << "\nStudent Found:\n";
            cout << "Name: " << arr1[i] << endl;
            cout << "Roll No: " << arr2[i] << endl;
            cout << "Course: " << arr3[i] << endl;
            cout << "Class: " << arr4[i] << endl;
            cout << "Contact: " << arr5[i] << endl;
            return;
        }
    }

    cout << "Student not found\n";
}

void update() {
    if (total == 0) {
        cout << "\nNo data is entered\n";
        return;
    }

    string rollno;
    cout << "Enter Roll No to update: ";
    cin >> rollno;

    for (int i = 0; i < total; i++) {
        if (rollno == arr2[i]) {
            cout << "\nEnter new data\n";

            cout << "Enter Name: ";
            cin >> arr1[i];

            cout << "Enter Roll No: ";
            cin >> arr2[i];

            cout << "Enter Course: ";
            cin >> arr3[i];

            cout << "Enter Class: ";
            cin >> arr4[i];

            cout << "Enter Contact: ";
            cin >> arr5[i];

            cout << "Record updated successfully\n";
            return;
        }
    }

    cout << "Student not found\n";
}

void deleterecord() {
    if (total == 0) {
        cout << "\nNo data is entered\n";
        return;
    }

    int choice;
    cout << "\n1. Delete all records\n2. Delete specific record\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        total = 0;
        cout << "All records deleted successfully\n";
    } 
    else if (choice == 2) {
        string rollno;
        cout << "Enter Roll No to delete: ";
        cin >> rollno;

        for (int i = 0; i < total; i++) {
            if (rollno == arr2[i]) {
                for (int j = i; j < total - 1; j++) {
                    arr1[j] = arr1[j + 1];
                    arr2[j] = arr2[j + 1];
                    arr3[j] = arr3[j + 1];
                    arr4[j] = arr4[j + 1];
                    arr5[j] = arr5[j + 1];
                }
                total--;
                cout << "Record deleted successfully\n";
                return;
            }
        }

        cout << "Student not found\n";
    } 
    else {
        cout << "Invalid choice\n";
    }
}

int main() {
    int value;

    while (true) {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Enter Data\n";
        cout << "2. Show Data\n";
        cout << "3. Search Data\n";
        cout << "4. Update Data\n";
        cout << "5. Delete Data\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> value;

        switch (value) {
            case 1: enter(); break;
            case 2: show(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: deleterecord(); break;
            case 6: exit(0);
            default: cout << "Invalid choice\n";
        }
    }
}
