#include <iostream>
#include <vector>
using namespace std;
int NO_PARENT = -1;
// ---------------------------------------
void printPath(int currentVertex, vector<int> parents)
{

    if (currentVertex == NO_PARENT) {
        return;
    }
    printPath(parents[currentVertex], parents);
    cout << currentVertex << " ";
}

// ---------------------------------------
void printSolution(int startVertex, vector<int> distances, vector<int> parents)
{
    int nVertices = distances.size();
    cout << "Vertex\t Distance\tPath";

    for (int vertexIndex = 0; vertexIndex < nVertices;
         vertexIndex++) {
        if (vertexIndex != startVertex) {
            cout << "\n" << startVertex << " -> ";
            cout << vertexIndex << " \t\t ";
            cout << distances[vertexIndex] << "\t\t";
            printPath(vertexIndex, parents);
        }
    }
}

// ---------------------------------------
void dijkstra (vector<vector<int>> graphMatrix, int startVertex) {
    int nVertices = graphMatrix.size();
    vector<int> distances (nVertices);
    vector<bool> isAdded (nVertices);
    vector<int> parents (nVertices);

    for (int i=0; i < nVertices; i++) {
        distances[i] = INT_MAX;
        isAdded[i] = false;
    }

    distances[startVertex] = 0;
    parents[startVertex] = NO_PARENT;

    for (int i = 0; i < nVertices; i++) {
        int nearestVertex = -1;
        int distance = INT_MAX;

        // find the vertex with minimum distance value
        for (int j = 0; j < nVertices; j ++) {
            if (! isAdded[j] && distances[j] < distance) {
                nearestVertex = j;
                distance = distances[j];
            }
        }

        isAdded[nearestVertex] = true;

        for (int k = 0; k < nVertices; k ++) {
            int edgeDistance = graphMatrix[nearestVertex][k];

            if (edgeDistance > 0 && ((distance + edgeDistance) < distances[k])) {
                parents [k] = nearestVertex;
                distances [k] = distance + edgeDistance;
            }
        }
    }

    printSolution(startVertex, distances, parents);
}

// ---------------------------------------
int main() {

    vector<vector<int> > adjacencyMatrix = {
            { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            { 0, 0, 4, 0, 10, 0, 2, 0, 0 },
            { 0, 0, 0, 14, 0, 2, 0, 1, 6 },
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(adjacencyMatrix, 0);

    return 0;
}
