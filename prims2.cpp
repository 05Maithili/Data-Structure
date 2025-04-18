#include<iostream>
#include<vector>
using namespace std;

class Prims {
public:
    int V;
    vector<vector<int>> graph;
    vector<string> cityNames; // Changed to public

    Prims(int vertices) {
        V = vertices;
        graph.resize(V, vector<int>(V, 0));
    }

    void inputCities() {
        cout << "Enter names of " << V << " cities:\n";
        for (int i = 0; i < V; i++) {
            string name;
            cin >> name;
            cityNames.push_back(name);
        }
    }

    void inputEdge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    int minKey(vector<int>& key, vector<bool>& mstSet) {
        int min = 1e9, minIndex = -1;
        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v], minIndex = v;
            }
        }
        return minIndex;
    }

    void printMST(vector<int>& parent) {
        cout << "\nMinimum Travel Path:\n";
        cout << "Edge \t\tWeight\n";
        int totalWeight = 0;
        for (int i = 1; i < V; i++) {
            cout << cityNames[parent[i]] << " - " << cityNames[i] 
                 << " \t" << graph[i][parent[i]] << "\n";
            totalWeight += graph[i][parent[i]];
        }
        cout << "Total Minimum Distance: " << totalWeight << "\n";
    }

    void primMST() {
        vector<int> parent(V);
        vector<int> key(V, 1e9);
        vector<bool> mstSet(V, false);
                                                                                                                                                                        
        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < V; v++) {
                if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }
        printMST(parent);
    }
};

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;
    Prims g(n);

    g.inputCities();

    cout << "\nEnter distances between cities (Enter 0 if no direct path exists):\n";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist;
            cout << "Distance between " << g.cityNames[i] << " and " << g.cityNames[j] << ": ";
            cin >> dist;
            if (dist != 0) {
                g.inputEdge(i, j, dist);
            }
        }
    }

    g.primMST();
    return 0;
}
