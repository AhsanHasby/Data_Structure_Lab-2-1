#include<bits/stdc++.h>
using namespace std;
#define V 4
#define INF 999

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            if(dist[i][j] == 0) {
                dist[i][j] = INF;
            }
        }
    }

    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                int d = dist[i][k] + dist[k][j];
                if(d < dist[i][j]) {
                    dist[i][j] = d;
                }
            }
        }
    }
    cout << "Shortest path using warshall algo:\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " "; 
        }
        cout << endl;
    }
}

int main() {
    int graph[V][V];
    cout << "Enter 4x4 matrix values: \n";

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cin >> graph[i][j]; 
        }
    }

    floydWarshall(graph);

    return 0;
}