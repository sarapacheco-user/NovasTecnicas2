// Grafos f=por matriz de adjacencia

#include <iostream>
#include <vector>
using namespace std;

void adjacencyMatrix() {
    int V = 4;
    vector<vector<int>> graph(V, vector<int>(V, 0));

    // Add edges
    graph[0][1] = 1; // Edge from node 0 to node 1
    graph[1][2] = 1; // Edge from node 1 to node 2

    // Print adjacency matrix
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}


// Lista de Adjacência

#include <iostream>
#include <vector>
using namespace std;

void adjacencyList() {
    int V = 4;
    vector<vector<int>> graph(V);

    // Add edges
    graph[0].push_back(1); // Edge from 0 to 1
    graph[1].push_back(2); // Edge from 1 to 2

    // Print adjacency list
    for (int i = 0; i < V; ++i) {
        cout << i << ": ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

// Vetor de Pares 

#include <iostream>
#include <vector>
using namespace std;

void edgeList() {
    vector<pair<int, int>> edges;

    // Add edges
    edges.push_back({0, 1});
    edges.push_back({1, 2});

    // Print edge list
    for (auto edge : edges) {
        cout << edge.first << " -> " << edge.second << endl;
    }
}


// Com classe

#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << i << ": ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

void objectOrientedGraph() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    g.printGraph();
}

// STL containers

#include <iostream>
#include <map>
#include <set>
using namespace std;

void stlGraph() {
    map<int, set<int>> graph;

    // Add edges
    graph[0].insert(1);
    graph[1].insert(2);

    // Print graph
    for (auto [node, neighbors] : graph) {
        cout << node << ": ";
        for (int neighbor : neighbors) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}
