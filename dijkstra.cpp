#include <iostream>
#include <limits.h>
using namespace std;

class graph {
public:
    int visit[100];
    int v;
    int g[100][100];
    int dist[100];

    graph(int v1) {
        v = v1;

        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                g[i][j] = 0; // Initialize adjacency matrix to 0
            }
            dist[i] = INT_MAX; // Initialize distances to infinity
            visit[i] = 0;      // Mark all vertices as unvisited
        }
    }

    void accept_edges(int x, int y, int w) {
        g[x][y] = w;
        g[y][x] = w; // Since the graph is undirected
    }

    void display() {
        cout << "\nAdjacency Matrix: \n";
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dijkstra(int src) {
        dist[src] = 0; // Distance to the source is 0

        for (int count = 0; count < v - 1; count++) {
            int min = INT_MAX, u = -1;

            // Find the unvisited vertex with the smallest distance
            for (int i = 0; i < v; i++) {
                if (visit[i] == 0 && dist[i] <= min) {
                    min = dist[i];
                    u = i; // ✅ Fixed: added missing semicolon
                }
            }

            if (u == -1)
                break; // All remaining vertices are unreachable

            visit[u] = 1; // Mark the vertex as visited

            // Update distances of adjacent vertices
            for (int i = 0; i < v; i++) {
                if (!visit[i] && g[u][i] && dist[u] != INT_MAX && dist[u] + g[u][i] < dist[i]) {
                    dist[i] = dist[u] + g[u][i];
                }
            }
        }

        // Print the shortest distances
        cout << "\nShortest distances from source (vertex " << src << "):" << endl;
        for (int i = 0; i < v; i++) {
            cout << "To vertex " << i << ": ";
            if (dist[i] == INT_MAX)
                cout << "Unreachable" << endl;
            else
                cout << dist[i] << endl;
        }
    }
};

int main() {
    int vertices = 5;
    graph g(vertices);

    g.accept_edges(0, 1, 3);
    g.accept_edges(0, 2, 2);
    g.accept_edges(0, 3, 8);
    g.accept_edges(1, 3, 7);
    g.accept_edges(2, 3, 4);
    g.accept_edges(2, 4, 9);
    g.accept_edges(3, 4, 6);
    g.display();

    int src;
    cout << "\nEnter the source vertex (0 to " << vertices - 1 << "): ";
    cin >> src;

    if (src >= 0 && src < vertices)
        g.dijkstra(src);
    else
        cout << "Invalid source vertex!" << endl;

    return 0;
}