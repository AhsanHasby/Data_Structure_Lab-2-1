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

    void dfs_helper(int u, vector<bool> &vis) { // O(V + E)
        vis[u] = true;
        cout << u << " ";

        list<int>neighbours = l[u];
        for(int v : neighbours) {
            if(!vis[v]) {
                dfs_helper(v, vis);
            }
        }
    }
    void dfs(int n) {
        vector<bool> vis(n, false);
        dfs_helper(0, vis);
        cout << endl;
    }

    bool path_helper(int src, int dest, vector<bool> &vis) {
        if(src == dest) {
            return true;
        }

        vis[src] = true;
        list<int> neighbours = l[src];

        for(int v : neighbours) {
            if(!vis[v]) {
                if(path_helper(v, dest, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool has_path(int src, int dest) {
        vector<bool> vis(V, false);

        return path_helper(src, dest, vis);
    }

};

// Solution using DFS:
int main() {
    int n = 7;
    Graph graph(n);
    
    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 3);
    graph.add_edge(2, 4);
    graph.add_edge(3, 4);
    graph.add_edge(3, 5);
    graph.add_edge(5, 6);

    // DFS solution of has_path problem:
    cout << graph.has_path(1, 6) << endl;
    cout << graph.has_path(1, 7) << endl;

    return 0;
}