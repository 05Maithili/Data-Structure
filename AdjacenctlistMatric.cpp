#include <iostream>
#include <cstring>
using namespace std;

#define MAX_CITIES 10

class Node {
public:
    int cityIndex;
    int cost;
    Node* next;
    
    Node(int index, int c) : cityIndex(index), cost(c), next(nullptr) {}

};

class Graph {
private:
    string cities[MAX_CITIES];
    Node* adjacencyList[MAX_CITIES];
    int adjacencyMatrix[MAX_CITIES][MAX_CITIES];
    int cityCount;

public:
    Graph() {
        cityCount = 0;
        for (int i = 0; i < MAX_CITIES; i++) {
            adjacencyList[i] = nullptr;
            for (int j = 0; j < MAX_CITIES; j++) {
                adjacencyMatrix[i][j] = -1;
            }
        }
    }

    int addCity(string cityName) {
        if (cityCount >= MAX_CITIES) return -1;
        cities[cityCount] = cityName;
        return cityCount++;
    }

    int getCityIndex(string cityName) {
        for (int i = 0; i < cityCount; i++) {
            if (cities[i] == cityName) return i;
        }
        return -1;
    }

    void addFlight(string cityA, string cityB, int cost) {
        int indexA = getCityIndex(cityA);
        int indexB = getCityIndex(cityB);
        if (indexA == -1 || indexB == -1) return;

        Node* newNode = new Node(indexB, cost);
        newNode->next = adjacencyList[indexA];
        adjacencyList[indexA] = newNode;
        adjacencyMatrix[indexA][indexB] = cost;
    }

    void displayAdjacencyList() {
        cout << "Adjacency List Representation:" << endl;
        for (int i = 0; i < cityCount; i++) {
            cout << cities[i] << " -> ";
            Node* temp = adjacencyList[i];
            while (temp) {
                cout << cities[temp->cityIndex] << "(" << temp->cost << ") -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    void displayAdjacencyMatrix() {
        cout << "\nAdjacency Matrix Representation:" << endl;
        cout << "    ";
        for (int i = 0; i < cityCount; i++) {
            cout << cities[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < cityCount; i++) {
            cout << cities[i] << " ";
            for (int j = 0; j < cityCount; j++) {
                if (adjacencyMatrix[i][j] == -1)
                    cout << "INF ";
                else
                    cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph flightNetwork;
    int choice;
    string cityA, cityB;
    int cost;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Add City\n";
        cout << "2. Add Flight\n";
        cout << "3. Display Adjacency List\n";
        cout << "4. Display Adjacency Matrix\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter city name: ";
                cin >> cityA;
                flightNetwork.addCity(cityA);
                break;
            case 2:
                cout << "Enter source city: ";
                cin >> cityA;
                cout << "Enter destination city: ";
                cin >> cityB;
                cout << "Enter cost: ";
                cin >> cost;
                flightNetwork.addFlight(cityA, cityB, cost);
                break;
            case 3:
                flightNetwork.displayAdjacencyList();
                break;
            case 4:
                flightNetwork.displayAdjacencyMatrix();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);
    
    return 0;
}