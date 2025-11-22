#include <iostream>
#include <vector>
#include <list>

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

};

int main() {
    Graph graph(5);

    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(1, 3);
    graph.add_edge(2, 3);
    graph.add_edge(2, 4);
    
    graph.print();

    return 0;
}