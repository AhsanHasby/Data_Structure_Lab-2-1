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

    void bfs() { // O(V + E)
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0] = true;

        while(q.size() > 0) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            
            list<int> neighbours = l[u]; // u-------v
            for(int v : neighbours) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
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

};

int main() {
    //Solve it using both DFS + BFS

    return 0;
}