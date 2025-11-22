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



};

int main() {
    Graph graph(5);

    return 0;
}