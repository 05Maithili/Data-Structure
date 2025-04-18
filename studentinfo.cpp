#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class student_info {
public:
    int rollno;
    string name;
    string Class;
    int per;
    string t;

    void accept() {
        cout << "\nEnter the roll.no of student: ";
        cin >> rollno;
        cout << "Enter the name of the student: ";
          
        cin>>name;
        cout << "Enter the class of the student: ";
        cin>> Class;
    }

    void display() {
        cout << setw(10) << left << rollno
             << setw(20) << left << name
             << setw(10) << left << Class
             << setw(10) << left << per
             << setw(50) << left << t << endl;
    }

    static void searching_byl(int n, student_info obj[]) {
        int roll_no;
        int flag = 0;
        cout << "\nEnter student roll.no to search: ";
        cin >> roll_no;
        for (int i = 0; i < n; i++) {
            if (roll_no == obj[i].rollno) {
                flag = 1;
                cout << "\nStudent " << obj[i].name << " was present in the training program\n";
                break;
            }
        }
        if (flag == 0) {
            cout << "\nStudent with roll number " << roll_no << " was not present in the training program\n";
        }
    }

    static void searching_byb(int n, student_info obj[]) {
        // Sorting array using bubble sort before binary search
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (obj[j].rollno > obj[j + 1].rollno) {
                    swap(obj[j], obj[j + 1]);
                }
            }
        }

        int low = 0, high = n - 1, mid;
        int flag = 0;
        int roll_no;
        cout << "\nEnter student roll.no to search: ";
        cin >> roll_no;

        while (low <= high) { // Binary search loop
            mid = (low + high) / 2;
            if (roll_no == obj[mid].rollno) {
                flag = 1;
                cout << "\nStudent " << obj[mid].name << " was present in the training program\n";
                break;
            } else if (roll_no < obj[mid].rollno) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (flag == 0) {
            cout << "\nStudent with roll number " << roll_no << " was not present in the training program\n";
        }
    }

    void survey() {
        int q1, q2, q3, q4, q5;
        cout << "\n1. Was the training session relevant to your needs? (1/0): ";
        cin >> q1;
        cout << "2. Were the training materials easy to understand? (1/0): ";
        cin >> q2;
        cout << "3. Did the training session meet your expectations? (1/0): ";
        cin >> q3;
        cout << "4. Was the trainer knowledgeable and effective? (1/0): ";
        cin >> q4;
        cout << "5. Would you recommend this training session to others? (1/0): ";
        cin >> q5;

        int total = q1 + q2 + q3 + q4 + q5;
        per = (total * 100) / 5; // Calculate percentage

        if (per >= 80) {
            t = "Conduct more programs like this in the future.";
        } else {
            t = "Do not conduct programs like this in the future.";
        }
    }

     
};

int main() 
{
    student_info obj[100];
    int n;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Store student data\n";
        cout << "2. Display data\n";
        cout << "3. Search student who have attended the training program (linear search)\n";
        cout << "4. Search student who have attended the training program (binary search)\n";
        cout << "5. Survey\n";
 
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter the number of students present in the training program: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    obj[i].accept();
                }
                break;
            case 2:
                cout << setw(10) << left << "Roll No"
                     << setw(20) << left << "Name"
                     << setw(10) << left << "Class"
                     << setw(10) << left << "Percent"
                     << setw(50) << left << "Feedback" << endl;
                cout << string(100, '-') << endl;
                for (int i = 0; i < n; i++) {
                    obj[i].display();
                }
                break;
            case 3:
                student_info::searching_byl(n, obj);
                break;
            case 4:
                student_info::searching_byb(n, obj);
                break;
            case 5:
                for (int i = 0; i < n; i++) {
                    obj[i].survey();
                }
                break;
             
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

return 0;
}