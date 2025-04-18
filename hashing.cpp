#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class Track {
public:
    int id;
    string name;
    string album;
    string artist;
    bool isDeleted;

    Track() {
        id = -1;           // -1 means empty
        isDeleted = false; // flag for logical deletion
    }
};

class MusicHash {
    Track table[TABLE_SIZE];

public:
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void addTrack() {
        int id;
        string name, album, artistName;

        cout << "Enter Track ID: ";
        cin >> id;
        cout << "Enter Track Name: ";
        cin >> name;
        cout << "Enter Album Name: ";
        cin >> album;
        cout << "Enter Artist Name: ";
        cin >> artistName;

        int index = hashFunction(id);
        for (int i = 0; i < TABLE_SIZE; i++) {
            int probe = (index + i) % TABLE_SIZE;
            if (table[probe].id == -1 || table[probe].isDeleted) {
                table[probe].id = id;
                table[probe].name = name;
                table[probe].album = album;
                table[probe].artist = artistName;
                table[probe].isDeleted = false;

                cout << (i == 0 ? "Track added at index " : "Collision! Track added at index ")
                     << probe << ".\n";
                return;
            }
        }
        cout << "Hash table is full. Cannot insert track.\n";
    }

    void searchTrack() {
        int id;
        cout << "Enter Track ID to search: ";
        cin >> id;

        int index = hashFunction(id);
        for (int i = 0; i < TABLE_SIZE; i++) {
            int probe = (index + i) % TABLE_SIZE;
            if (table[probe].id == id && !table[probe].isDeleted) {
                cout << "\nTrack found at index " << probe << ":\n";
                cout << "Track ID: " << table[probe].id << endl;
                cout << "Track Name: " << table[probe].name << endl;
                cout << "Album Name: " << table[probe].album << endl;
                cout << "Artist: " << table[probe].artist << endl;
                return;
            }
            if (table[probe].id == -1) break;
        }
        cout << "Track not found.\n";
    }

    void updateTrack() {
        int id;
        cout << "Enter Track ID to update: ";
        cin >> id;

        int index = hashFunction(id);
        for (int i = 0; i < TABLE_SIZE; i++) {
            int probe = (index + i) % TABLE_SIZE;
            if (table[probe].id == id && !table[probe].isDeleted) {
                cout << "Enter new Track Name: ";
                cin >> table[probe].name;
                cout << "Enter new Album Name: ";
                cin >> table[probe].album;
                cout << "Enter new Artist Name: ";
                cin >> table[probe].artist;
                cout << "Track updated successfully at index " << probe << ".\n";
                return;
            }
            if (table[probe].id == -1) break;
        }
        cout << "Track not found.\n";
    }

    void deleteTrack() {
        int id;
        cout << "Enter Track ID to delete: ";
        cin >> id;

        int index = hashFunction(id);
        for (int i = 0; i < TABLE_SIZE; i++) {
            int probe = (index + i) % TABLE_SIZE;
            if (table[probe].id == id && !table[probe].isDeleted) {
                table[probe].isDeleted = true;
                cout << "Track deleted from index " << probe << ".\n";
                return;
            }
            if (table[probe].id == -1) break;
        }
        cout << "Track not found.\n";
    }

    void displayTracks() {
        cout << "\n--- Hash Table Contents ---\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].id != -1 && !table[i].isDeleted) {
                cout << "Index " << i << ": Track ID: " << table[i].id
                     << ", Name: " << table[i].name
                     << ", Album: " << table[i].album
                     << ", Artist: " << table[i].artist << endl;
            } else {
                cout << "Index " << i << ": [Empty]\n";
            }
        }
    }
};

int main() {
    MusicHash mh;
    int choice;
    while (true) {
        cout << "\n1. Add Track\n2. Search Track\n3. Display Tracks\n4. Update Track\n5. Delete Track\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: mh.addTrack(); break;
            case 2: mh.searchTrack(); break;
            case 3: mh.displayTracks(); break;
            case 4: mh.updateTrack(); break;
            case 5: mh.deleteTrack(); break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}