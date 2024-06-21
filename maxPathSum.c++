#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

void addEdge(vector<vector<int>> &Graph, vector<pair<int, int>> &Edges) {
    for(auto edge : Edges) {
        Graph[edge.first][edge.second] = 1;
        // Assuming it's an undirected graph, so adding both directions
        Graph[edge.second][edge.first] = 1;
    }
}

// Depth-First Search to find the path with maximum sum
void DFS(vector<vector<int>> &Graph, int v, int start, vector<bool> &visited, vector<int> &path, vector<int> &maxPath, int &maxSum, int currSum) {
    visited[start] = true;
    path.push_back(start);
    currSum += start;
    
    // If we reach the last vertex (v-1 in 0-based indexing), check if this path has a higher sum
    if (start == v - 1) {
        if (currSum > maxSum) {
            maxSum = currSum;
            maxPath = path;
        }
    } else {
        for (int i = 0; i < v; ++i) {
            if (Graph[start][i] == 1 && !visited[i]) {
                DFS(Graph, v, i, visited, path, maxPath, maxSum, currSum);
            }
        }
    }
    
    // Backtrack
    visited[start] = false;
    path.pop_back();
}

// Function to find and print the maximum sum path
void printMaximumSumPath(vector<vector<int>> &Graph, int v) {
    vector<bool> visited(v, false);
    vector<int> path, maxPath;
    int maxSum = INT_MIN;
    int currSum = 0;
    
    // Start DFS from vertex 0
    DFS(Graph, v, 0, visited, path, maxPath, maxSum, currSum);
    
    // Print the path with maximum sum
    cout << "Maximum sum path: ";
    for (int i = 0; i < maxPath.size(); ++i) {
        cout << maxPath[i];
        if (i != maxPath.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
    cout << "Maximum sum: " << maxSum << endl;
}

int main() {
    int v, e;
    cout << "Enter the no. of vertices: ";
    cin >> v;
    cout << "Enter the no. of edges: ";
    cin >> e;

    vector<vector<int>> Graph(v, vector<int>(v, 0));
    vector<pair<int, int>> Edges;
    
    for (int i = 0; i < e; i++) {
        cout << "Enter the vertices for edge " << i + 1 << ": ";
        int s, d;
        cin >> s >> d;
        Edges.push_back({s, d});
    }
    
    addEdge(Graph, Edges);
    
    printMaximumSumPath(Graph, v);
    
    return 0;
}
