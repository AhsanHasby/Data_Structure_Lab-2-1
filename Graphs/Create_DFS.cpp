#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
    int V;
    list<int> * l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }
    void add_edge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print() {
        for(int u = 0; u < V; ++u) {
            list<int> neighbour = l[u];
            cout << u << ": ";
            for(int v : neighbour) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
    void dfs(int u, vector<bool> &vis) {
        vis[u] = true;
        cout << u << " ";

        list<int>neighbours = l[u];
        for(int v : neighbours) {
            if(!vis[v]) {
                dfs(v, vis);
            }
        }
    }

};

int main() {
    Graph graph(7);

    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 3);
    graph.add_edge(2, 4);
    graph.add_edge(3, 4);
    graph.add_edge(3, 5);
    graph.add_edge(4, 5);
    graph.add_edge(5, 6);
    // Traverse
    cout << "Traverse" << endl;
    graph.print();
    //DFS
    cout << "Depth First Search" << endl;
    vector<bool> vis(7, false);
    graph.dfs(0, vis);

    return 0;
}