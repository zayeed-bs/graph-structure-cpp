// GraphStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


// Store adjacency list items
struct adjNode {
    int val, cost;
    adjNode* next;
};

// Structure to store the edges (the connections)
// start_ver: Initial Vertex it starts from
// end_ver: The vertex it connects to
// weight: cost of edge

struct edge {
    int start_ver, end_ver, weight;
};

class Graph {
    // insert new nodes into adjacency list from given graph
    adjNode* getAdjListNode(int value, int weight, adjNode* head) {
        adjNode* newNode = new adjNode;
        newNode->val = value;
        newNode->cost = weight;

        newNode->next = head; // point new node to current head

        return newNode;
    }

    int N; // Number of total Nodes in the graph

    public:
        adjNode** head;

        Graph(edge edges[], int n, int N) {

            //allocate new node

            head = new adjNode * [N]();
            this->N = N;
            
            // initialize head pointer for all vertices
            for (int i = 0; i < N; ++i)
                head[i] = nullptr;

            // construct directed graph by adding edges to it
            for (unsigned i = 0; i < n; i++) {
                int start_ver = edges[i].start_ver;
                int end_ver = edges[i].end_ver;
                int weight = edges[i].weight;
                // insert in the beginning
                adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);

                // point head pointer to new node
                head[start_ver] = newNode;
            }

            
        }

        // Destructor
        ~Graph() {
            for (int i = 0; i < N; i++)
                delete[] head[i];
                delete[] head;
        }
};

// print all adjacent vertices of given vertex
void display_AdjList(adjNode* ptr, int i)
{
    while (ptr != nullptr) {
        cout << "(" << i << ", " << ptr->val
            << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    edge edges[] = {
        // (x, y, w) -> edge from x to y with weight w
        {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
    };

    int N = 6;  // Number of vertices in the graph

    // calculate number of edges
    int n = sizeof(edges) / sizeof(edges[0]); // divide total size of edges by size of one edge

    Graph graph(edges, n, N);
    
    // print adjacency list representation of graph
    cout << "Graph adjacency list " << endl << "(start_vertex, end_vertex, weight):" << endl;
    for (int i = 0; i < N; i++)
    {
        // display adjacent vertices of vertex i
        display_AdjList(graph.head[i], i);
    }
    return 0;
}