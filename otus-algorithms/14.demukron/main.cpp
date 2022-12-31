#include <iostream>
#include <list>
#include <vector>

class Graph {
public:
    Graph (int numOfVertices);

    void addEdge (int v, int w);
    void printGraph ();
    void createMatrix ();
    void printMatrix();
    void sort();

private:
    int numOfVertices;
    std::vector <int> *graphEdges;
    int **adjacencyMatrix = new int* [numOfVertices];
    int *sum = new int [numOfVertices];
    int *calcSum ();
    void subtract (int rowNumber);
};

// ---------------------------------------
Graph::Graph (int numOfVertices) {
    this->numOfVertices = numOfVertices;
    graphEdges = new std::vector<int>[numOfVertices];
}

// ---------------------------------------
void Graph::addEdge (int u, int v) {
    graphEdges[u].push_back(v);
}

// ---------------------------------------
void Graph::printGraph () {
    for (int i = 0; i < numOfVertices; i++) {
        std::cout << "\nvertex " << i << " : ";
        for (auto x : graphEdges[i]) std::cout <<"->" << x;
    }
}

// ---------------------------------------
void Graph::printMatrix() {
    std::cout << "\nMatrix:\n";
    for (int i = 0; i < numOfVertices; i++) {
        for (int j = 0; j < numOfVertices; j++)
            std::cout << adjacencyMatrix[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "----------------\n";
    for (int i = 0; i < numOfVertices; i++)
        std::cout << sum[i] << " ";
}

// ---------------------------------------
void Graph::createMatrix () {

    // ------- Adjacency Matrix Empty --------
    for (int i = 0; i < numOfVertices; i++) {
        adjacencyMatrix[i] = new int[numOfVertices];
        for (int j = 0; j < numOfVertices; j++)
            adjacencyMatrix[i][j] = 0;
    }
    // ------- Adjacency Matrix Filled -------
    for (int i = 0; i < numOfVertices; i++) {
        sum[i] = 0;
        for (int j = 0; j < graphEdges[i].size(); j++) {
            adjacencyMatrix[i][graphEdges[i][j]] = 1;
        }
    }
    // ------- Sum Matrix by columns ---------
    for (int i = 0; i < numOfVertices; i++) {
        for (int j = 0; j < numOfVertices; j++) {
            if (adjacencyMatrix[i][j] == 1) sum[j] += 1;
        }
    }
}

// ---------------------------------------
int * Graph::calcSum() {
    int *retval = new int[numOfVertices];

    for (int i = 0; i < numOfVertices; i++) {
        for (int j = 0; j < numOfVertices; j++) {
            retval[j] += adjacencyMatrix[i][j];
        }
    }
    return retval;
}

// ---------------------------------------
void Graph::subtract(int rowNumber) {
    for (int i = 0; i < numOfVertices; i++) {
        for (int j = 0; j < numOfVertices; j++) {
            adjacencyMatrix[i][j] -= adjacencyMatrix[rowNumber][j];
            if (adjacencyMatrix[i][j] < 0) adjacencyMatrix[i][j] = 0;
        }
    }
}

// ---------------------------------------
void Graph::sort (){
    createMatrix();
    printMatrix();

    // ---------------------------------------
    std::vector <int> order;
    std::vector <int> subtractList;

    bool iscontains = 0;

    for (int i = 0; i < numOfVertices; i++) {
        for (int j = 0; j < numOfVertices; j++) {
            sum = calcSum();
            if (std::find(order.begin(), order.end(), j) != order.end()) iscontains = 1;

            if (sum[j] == 0 && !iscontains) {
                order.push_back(j);
                subtractList.push_back(j);
            }
        }

        for (int s : subtractList) {
                std::cout <<"\nsubtracting row #"<< s << std::endl;
                subtract(s);
                sum = calcSum();
                printMatrix();
            }

        subtractList.clear();
    }

    std::cout << "\n// ---- Graph Vertex Ordering ----\n";
    for (int i = 0; i < numOfVertices; i++)
        std::cout << order[i] << " ";
}

// ---------------------------------------
int main() {

    std::cout << "\n// ------- Initial Graph  --------\n";
    Graph graphTest(8);
    graphTest.addEdge(0, 1);
    graphTest.addEdge(1, 2);
    graphTest.addEdge(2, 3);
    graphTest.addEdge(3, 0);
    graphTest.addEdge(2, 4);
    graphTest.addEdge(4, 2);
    graphTest.addEdge(4, 1);
    graphTest.addEdge(4, 0);
    graphTest.addEdge(5, 2);
    graphTest.addEdge(6, 2);
    graphTest.addEdge(7, 1);
    graphTest.addEdge(7, 2);

    graphTest.printGraph();
    graphTest.sort();

    return 0;
}
