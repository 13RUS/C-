#include <iostream>
#include "vector"
#include "stack"

// ---------------------------------------
void addEdge (std::vector<int> graph[], int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

// ---------------------------------------
void printGraph (std::vector<int> graph[], int numOfVertex) {
    for (int i = 0; i < numOfVertex; i++) {
        std::cout << "\nEdges of vertex " << i << " : ";
        for (auto x : graph [i]) std::cout <<"->" << x;
    }
}

// ---------------------------------------
int n, m;

const int maxVertices = 8;

struct Node {
    std::vector<int> graph;
    std::vector<int> graph_reversed;
};

Node graphTest[maxVertices];

std::stack<int> S;
bool visited[maxVertices];

int component[maxVertices];
std::vector<int> components [maxVertices];
int numComponents;

// ---------------------------------------
void dfs1 (int x) {
    visited[x] = true;

    for (int i = 0; i < graphTest[x].graph.size(); i++)
        if (!visited[graphTest[x].graph[i]]) dfs1(graphTest[x].graph[i]);

    S.push(x);
}

// ---------------------------------------
void dfs2 (int x) {
    printf("%d ", x);

   // component[x] = numComponents;
    components[numComponents].push_back(x);
    visited[x] = true;

    for (int i = 0; i < graphTest[x].graph_reversed.size(); i++)
        if (!visited[graphTest[x].graph_reversed[i]]) dfs2(graphTest[x].graph_reversed[i]);

}

// ---------------------------------------
void Kosaraju () {
    for (int i = 0; i < n; i++)
        if (!visited[i]) dfs1(i);

    for (int i = 0; i < n; i++)
        visited[i] = false;

    while (!S.empty()) {
        int v = S.top(); S.pop();

        if (!visited[v]) {
            printf("\nComponent %d: ", numComponents);
            dfs2(v);
            numComponents++;
        }
    }
}

// ---------------------------------------
int main() {

    std::cout << "\n// -------------- Graph Basic Functions --------------\n";
    int V = 5;
    std::vector<int> testGraph[V];
    addEdge(testGraph, 0, 1);
    addEdge(testGraph, 0, 4);
    addEdge(testGraph, 1, 2);
    addEdge(testGraph, 1, 3);
    addEdge(testGraph, 1, 4);
    addEdge(testGraph, 2, 3);
    addEdge(testGraph, 3, 4);
    printGraph(testGraph, V);

    std::cout << "\n\n// -------------------- Kosaraju ---------------------\n";
    n = 8, m = 14;

    // graph
    graphTest[0].graph.push_back(1);
    graphTest[1].graph.push_back(2);
    graphTest[1].graph.push_back(4);
    graphTest[1].graph.push_back(5);
    graphTest[2].graph.push_back(3);
    graphTest[2].graph.push_back(6);
    graphTest[3].graph.push_back(2);
    graphTest[3].graph.push_back(7);
    graphTest[4].graph.push_back(5);
    graphTest[5].graph.push_back(6);
    graphTest[6].graph.push_back(5);
    graphTest[7].graph.push_back(3);
    graphTest[7].graph.push_back(6);

    // reverse graph
    graphTest[1].graph_reversed.push_back(0);
    graphTest[2].graph_reversed.push_back(1);
    graphTest[4].graph_reversed.push_back(1);
    graphTest[5].graph_reversed.push_back(1);
    graphTest[3].graph_reversed.push_back(2);
    graphTest[6].graph_reversed.push_back(2);
    graphTest[2].graph_reversed.push_back(3);
    graphTest[7].graph_reversed.push_back(3);
    graphTest[5].graph_reversed.push_back(4);
    graphTest[6].graph_reversed.push_back(5);
    graphTest[5].graph_reversed.push_back(6);
    graphTest[3].graph_reversed.push_back(7);
    graphTest[6].graph_reversed.push_back(7);

    Kosaraju();
    std::cout << "\nTotal number of components: " << numComponents;

    std::cout << "\n\n// -------------- Print Components Graph -------------\n";

    printGraph(components, n);

    return 0;
}
