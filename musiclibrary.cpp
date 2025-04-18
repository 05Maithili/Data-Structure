#include <iostream>
#include <string>
using namespace std;

// Structure to store music track details
struct Track {
    string title;
    string artist;
    string album;
    string genre;
    int duration; // duration in seconds
    int releaseYear;
};

// Node structure for the singly linked list
struct Node {
    Track track;
    Node* next;
};

// Singly Linked List Class
class MusicLibrary {
private:
    Node* head;

public:
    MusicLibrary() : head(nullptr) {}

    // Function to add a new track
    void addTrack(const Track& newTrack) {
        Node* newNode = new Node{newTrack, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Track added: " << newTrack.title << endl;
    }

    // Function to remove a track by title
    void removeTrack(const string& title) {
        if (!head) {
            cout << "Library is empty!" << endl;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->track.title == title) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                cout << "Track removed: " << title << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Track not found: " << title << endl;
    }

    // Function to search for a track
    void searchTrack(const string& title) {
        if (!head) {
            cout << "Library is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->track.title == title) {
                cout << "Track found:\n"
                     << "Title: " << temp->track.title << "\n"
                     << "Artist: " << temp->track.artist << "\n"
                     << "Album: " << temp->track.album << "\n"
                     << "Genre: " << temp->track.genre << "\n"
                     << "Duration: " << temp->track.duration << " seconds\n"
                     << "Release Year: " << temp->track.releaseYear << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Track not found: " << title << endl;
    }

    // Function to display all tracks
    void displayTracks() {
        if (!head) {
            cout << "Library is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << "Title: " << temp->track.title << ", Artist: " << temp->track.artist
                 << ", Album: " << temp->track.album << ", Genre: " << temp->track.genre
                 << ", Duration: " << temp->track.duration << " seconds, Release Year: "
                 << temp->track.releaseYear << endl;
            temp = temp->next;
        }
    }

    // Destructor to free memory
    ~MusicLibrary() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    MusicLibrary library;
    int choice;

    do {
        cout << "\n--- Music Library Menu ---\n";
        cout << "1. Add Track\n";
        cout << "2. Remove Track\n";
        cout << "3. Search Track\n";
        cout << "4. Display All Tracks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Track newTrack;
                cout << "Enter Track Title: ";
                cin.ignore();
                getline(cin, newTrack.title);
                cout << "Enter Artist: ";
                getline(cin, newTrack.artist);
                cout << "Enter Album: ";
                getline(cin, newTrack.album);
                cout << "Enter Genre: ";
                getline(cin, newTrack.genre);
                cout << "Enter Duration (in seconds): ";
                cin >> newTrack.duration;
                cout << "Enter Release Year: ";
                cin >> newTrack.releaseYear;

                library.addTrack(newTrack);
                break;
            }
            case 2: {
                string title;
                cout << "Enter the title of the track to remove: ";
                cin.ignore();
                getline(cin, title);

                library.removeTrack(title);
                break;
            }
            case 3: {
                string title;
                cout << "Enter the title of the track to search: ";
                cin.ignore();
                getline(cin, title);

                library.searchTrack(title);
                break;
            }
            case 4:
                library.displayTracks();
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
