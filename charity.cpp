#include <iostream>
#include <cstring>
using namespace std;

struct charity {
    int donation_id;
    string donor_name;
    int donation_amount;
    struct charity *next;
};

class donation_info {
private:
    charity *head;

public:
    donation_info() {
        head = NULL;
    }

    void addinfo(int id, int amount, string name) {
        charity *temp = new charity;
        temp->donation_id = id;
        temp->donation_amount = amount;
        temp->donor_name = name;

        if (!head) {
            head = temp;
            temp->next = head; // Circular link
        } else {
            charity *last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = temp;
            temp->next = head; // Circular link
        }

        cout << "\nDonor added successfully.\n";
    }

    void display() {
        if (!head) {
            cout << "\nThere is no data available.\n";
            return;
        }

        charity *temp = head;
        do {
            cout << "\nDonor Name: " << temp->donor_name;
            cout << "\nDonation ID: " << temp->donation_id;
            cout << "\nDonation Amount: " << temp->donation_amount << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void updatedata(int id, int amount, string name) {
        if (!head) {
            cout << "\nThere is no data to update.\n";
            return;
        }

        charity *temp = head;
        bool found = false;

        do {
            if (id == temp->donation_id) {
                temp->donor_name = name;
                temp->donation_amount = amount;
                found = true;
                cout << "\nData updated successfully.\n";
                break;
            }
            temp = temp->next;
        } while (temp != head);

        if (!found) {
            cout << "\nInvalid donor ID.\n";
        }
    }

    void remove(int id) {
        if (!head) {
            cout << "\nThere is no data to remove.\n";
            return;
        }

        charity *temp = head;
        charity *prev = NULL;
        bool found = false;

        do {
            if (temp->donation_id == id) {
                found = true;
                break;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        if (!found) {
            cout << "\nDonor not found.\n";
            return;
        }

        if (temp == head && temp->next == head) {
            // Only one node
            head = NULL;
        } else if (temp == head) {
            // Removing head node
            charity *last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
        } else {
            // Removing non-head node
            prev->next = temp->next;
        }

        delete temp;
        cout << "\nInformation deleted successfully.\n";
    }

    void search(int id) {
        if (!head) {
            cout << "\nThere is no data to search.\n";
            return;
        }

        charity *temp = head;
        bool found = false;

        do {
            if (temp->donation_id == id) {
                cout << "\nDonor found:";
                cout << "\nDonor Name: " << temp->donor_name;
                cout << "\nDonation ID: " << temp->donation_id;
                cout << "\nDonation Amount: " << temp->donation_amount << endl;
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != head);

        if (!found) {
            cout << "\nDonor not found.\n";
        }
    }
};

int main() {
    donation_info obj1;
    int ch, id, amount;
    string name;

    do {
        cout << "\nEnter your choice:\n1. Insert donation info\n2. Display\n3. Update\n4. Remove\n5. Search\n6. Exit\nChoice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter Donor Name: ";
                cin >> name;
                cout << "Enter Donation ID: ";
                cin >> id;
                cout << "Enter Donation Amount: ";
                cin >> amount;
                obj1.addinfo(id, amount, name);
                break;

            case 2:
                obj1.display();
                break;

            case 3:
                cout << "\nEnter Donation ID to update: ";
                cin >> id;
                cout << "Enter New Donor Name: ";
                cin >> name;
                cout << "Enter New Donation Amount: ";
                cin >> amount;
                obj1.updatedata(id, amount, name);
                break;

            case 4:
                cout << "\nEnter Donation ID to remove: ";
                cin >> id;
                obj1.remove(id);
                break;

            case 5:
                cout << "\nEnter Donation ID to search: ";
                cin >> id;
                obj1.search(id);
                break;

            case 6:
                cout << "\nExiting program.\n";
                break;

            default:
                cout << "\nInvalid choice.\n";
                break;
        }
    } while (ch != 6);

    return 0;
}
