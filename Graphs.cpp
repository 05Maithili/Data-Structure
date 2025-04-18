#include<iostream>
#include<string>
using namespace std;
class Graph
{
    int u, v;
    int m[4][4];
public:
    Graph(int x, int y)
    {
        u = x;
        v = y;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                m[i][j] = 0;
            }
        }
    }

    void edge(int u, int v)
    {
        m[u][v] = 1;
        m[v][u] = 1;
    }

    void display()
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                 cout<<m[i][j];
            }
            cout<<endl;
        }
    }
};

 

int main()
{
    Graph g(4, 4);
    //g.edge(1, 2);
    // g.edge(2, 3);
    //g.edge(3, 4);
    //g.display();
    int edge;
    int vertices,u,v;
    int i, j;
    cout<<"\nEnter the number of vertices: ";
    cin>>vertices;
    cout<<"\nEnter the number of Edges: ";
    cin>>edge;
    for(i=0;i<edge;i++)
    {
        cout<<"Enter value of u and v: ";
        cin>>u>>v;
        g.edge(u,v);
    }

    cout<<"Adjacency Matrix:"<<endl;
    g.display();
    return 0;
}