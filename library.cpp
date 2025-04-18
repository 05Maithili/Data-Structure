#include<iostream>
#include<string>
using namespace std;

class college_library {
public:
    int book_cost;
    string book_name;

    int storing() {
        cout << "\nEnter the cost of book:\t";
        cin >> book_cost;
        cout << "\nEnter the name of book:\t";
        cin.ignore();  // Ignore the leftover newline character from previous input
        getline(cin , book_name);  // Read the entire line for book name
        return 0;
    }

    void display() {
        cout << book_name << "\t\t" << book_cost << "\n";
    }

    static void descending(int n, college_library book_details[]) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (book_details[i].book_cost < book_details[j].book_cost) {
                    swap(book_details[i], book_details[j]);
                }
            }
        }

        cout << "\nSorted data (based on book cost) in descending order:\n";
        for (int i = 0; i < n; i++) {
            book_details[i].display();
        }
    }

    static void costwise(int n, college_library book_details[]) {
        int count = 0;
        cout << "\nBooks with cost less than 500:\n";
        for (int i = 0; i < n; i++) {
            if (book_details[i].book_cost < 500) {
                book_details[i].display();
            } else {
                count++;
            }
        }
        cout << "\nNumber of books with cost more than 500:\t" << count << "\n";
    }

    static void deleteduplicatet(int& n, college_library book_details[]) {
        int n1 = 0;
        college_library Temp[10];
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = 0; j < n1; j++) {
                if (Temp[j].book_cost == book_details[i].book_cost) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                Temp[n1] = book_details[i];
                n1++;
            }
        }

        n = n1;
        for (int i = 0; i < n; i++) {
             Temp[i];
        }

        cout << "\nBook Details after removing duplicates by cost:\n";
        cout << "Name\t\tCost\n";
        for (int i = 0; i < n; i++) {
            Temp[i].display();
        }
    }

    static void deleteduplicate(int& n, college_library book_details[]) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (book_details[j].book_name == book_details[i].book_name) {
                    for (int k = j; k < n - 1; k++) {
                        book_details[k] = book_details[k + 1];
                    }
                    n--; // Reduce the total count
                    j--; // Recheck the current position
                }
            }
        }
        cout << "\nBook Details after removing duplicates by name:\n";
        cout << "Name\t\tCost\n";
        for (int i = 0; i < n; i++) {
            book_details[i].display();
        }
    }
};

int main() {
    college_library book_details[10];
    int n;
    int choice;
    do {
        cout << "\nEnter choice:\t";
        cout << "\n1. Store library data";
        cout << "\n2. Display data";
        cout << "\n3. Sort data in descending order of cost";
        cout << "\n4. Cost of books less than 500 & count of books having cost greater than 500";
        cout << "\n5. Delete similar cost book data using temporary array";
        cout << "\n6. Delete similar name book data without using a temporary array";
        cout << "\n7. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter Number of books present in library:\t";
                cin >> n;

                for (int i = 0; i < n; i++) {
                    cout << "\nEnter the details for position " << i << "\n";
                    book_details[i].storing();
                }
                break;

            case 2:
                cout << "\n\nBook Details for Each Book:\n";
                cout << "\nBook Details:\n";
                cout << "Name\t\tCost\n";
                for (int i = 0; i < n; i++) {
                    book_details[i].display();
                }
                break;

            case 3:
                college_library::descending(n, book_details);
                break;

            case 4:
                college_library::costwise(n, book_details);
                break;

            case 5:
                college_library::deleteduplicatet(n, book_details);
                break;

            case 6:
                college_library::deleteduplicate(n, book_details);
                break;

            case 7:
                cout << "\nExiting...\n";
                break;

            default:
                cout << "\nInvalid choice...!!!\n";
                break;
        }
    } while (choice != 7);

    return 0;
}
