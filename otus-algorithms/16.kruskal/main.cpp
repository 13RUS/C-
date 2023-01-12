#include <iostream>
#include <vector>
using namespace std;


#define edge pair<int, int>

class Graph {
public:
    Graph (int numberOfVertices);
    void addEdge (int u, int v, int w);
    int find_set (int i);
    void union_set (int u, int v);
    void kruskal();
    void printGraph();

private:
    vector<pair <int, edge> > G; // graph
    vector<pair <int, edge> > MST;
    int *parent;
    int numberOfVertices;
};

// ---------------------------------------
Graph::Graph(int numberOfVertices) {
    parent = new int [numberOfVertices + 1];

    for (int i = 0; i < numberOfVertices; i++)
        parent[i] = i;

    G.clear();
    MST.clear();
}

// ---------------------------------------
void Graph::addEdge(int u, int v, int w) {
    G.push_back(make_pair(w, edge(u ,v)));
}

// ---------------------------------------
int Graph::find_set(int i) {
    if (i == parent[i])
        return i;
    else
        return find_set(parent[i]);
}

// ---------------------------------------
void Graph::union_set(int u, int v) {
    parent[u] = parent[v];
}

// ---------------------------------------
void Graph::kruskal() {
    int i, a, b;

    sort(G.begin(), G.end());

    for (i = 0; i < G.size(); i++) {
        a = find_set(G[i].second.first);
        b = find_set(G[i].second.second);

        if (a != b) {
            MST.push_back(G[i]);
            union_set(a, b);
        }
    }
}

// ---------------------------------------
void Graph::printGraph()  {
    int MSTcost = 0;
    cout << "\nFollowing are the edges in the constructed MST" << endl;
    cout << "\nEdge  =" << " Weight" << endl;
    for (int i = 0; i < MST.size(); i++) {
        cout << MST[i].second.first << " - " << MST[i].second.second << " = " << MST[i].first << endl;
        MSTcost += MST[i].first;
    }

    cout << "Minimum Cost Spanning Tree: " << MSTcost;
}

// ---------------------------------------
int main() {


/* We create following weighted graph
                   10
              0--------1
              |  \     |
             6|   5\   |15
              |      \ |
              2--------3
                  4       */

    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);

    g.kruskal();
    g.printGraph();

    Graph g2(9);
    g2.addEdge(0, 1, 4);
    g2.addEdge(0, 7, 8);
    g2.addEdge(1, 2, 8);
    g2.addEdge(1, 7, 11);
    g2.addEdge(2, 3, 7);
    g2.addEdge(2, 8, 2);
    g2.addEdge(2, 5, 4);
    g2.addEdge(3, 4, 9);
    g2.addEdge(3, 5, 14);
    g2.addEdge(4, 5, 10);
    g2.addEdge(5, 6, 2);
    g2.addEdge(6, 7, 1);
    g2.addEdge(6, 8, 6);
    g2.addEdge(7, 8, 7);
    g2.kruskal();
    g2.printGraph();

    return 0;
}
