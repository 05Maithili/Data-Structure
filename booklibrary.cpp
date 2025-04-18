#include<iostream>
#include<cstring>
using namespace std;

class book {
public:
    string bookName;
    string bookAuthor;
    int ISBN;
    bool avaibility;
    book* next;

    book(string name, string author, int no, bool available) {
        bookName = name;
        bookAuthor = author;
        ISBN = no;
        avaibility = available;
        next = NULL;
    }
};

void insertbook(book* &head, string name, string author, int no, bool available) {
    book* new_book = new book(name, author, no, available);
    if (head == NULL) {
        head = new_book; // Correctly assign new_book to head
    } else {
        book* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_book;
    }
}

void display(book* head) {
    book* temp = head;
    if (temp == NULL) {
        cout << "\nThere is no such book available.";
        return;
    }
    while (temp != NULL) {
        cout << "\nBook name:\t" << temp->bookName;
        cout << "\nBook author:\t" << temp->bookAuthor;
        cout << "\nISBN:\t" << temp->ISBN;
        if (!temp->avaibility) { // Check if the book is not available
            cout << "\nBook is not available.";
        } else {
            cout << "\nBook is available.";
        }
        temp = temp->next;
    }
    cout << endl;
}

void searchbook(book* &head, string name, string author) {
    book* temp = head;
    int flag = 0;
    while (temp != NULL) {
        if (name == temp->bookName && author == temp->bookAuthor) {
            flag = 1;
            cout << "\nBook Found.";
            break;
        }
        temp = temp->next;
    }
    if (flag != 1) {
        cout << "\nBook Not Found.";
    }
}

void deletebook(book*& head, string name, string author) {
    book* temp = head;
    book* prev = NULL;

    while (temp != NULL) {
        if (temp->bookName == name && temp->bookAuthor == author) {
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "\nBook not found." << endl;
        return;
    }

    if (prev == NULL) {
        head = temp->next; // Update head if the first book is deleted
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "\nBook deleted successfully." << endl;
}

int main() {
    book* head = NULL;
    int ch;
    string name, author;
    int no; 
    bool available;

    do {
        cout << "\nEnter your choice:-";
        cout << "\n1. Insert book\n2. Display books\n3. Delete book\n4. Search book\n5. Exit\n";
        cout << "Choice: ";
        cin >> ch;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (ch) {
            case 1:
                cout << "\nEnter the book name:\t";
                 cin>> name; // Use getline to read book name
                cout << "Enter the book author:\t";
                 cin>> author; // Use getline to read author name
                cout << "Enter ISBN:\t";
                cin >> no;
                cout << "Is the book available (1/0):\t";
                cin >> available;
                insertbook(head, name, author, no, available);
                break;
           
            case 2:
                cout << "\nLibrary Collection:";
                display(head);
                break;
            case 3:
                cout << "\nEnter the book name to delete:\t";
                cin>>name;
                cout << "Enter the book author:\t";
                cin>>author;
                deletebook(head, name, author);
                break;
            case 4:
                cout << "\nEnter the book name to delete:\t";
                cin>>name;
                cout << "Enter the book author:\t";
                cin>>author;
                searchbook(head, name, author);
                break;
            case 5:
                cout << "\nExiting the program.";
                break;
            default:
                cout << "\nInvalid choice. Please try again.";
        }
    } while (ch != 5);

    return 0;
}