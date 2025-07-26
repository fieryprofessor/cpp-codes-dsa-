//Given an undirected graph and an integer M, determine if the graph can be colored with
// at most M colors such that no two adjacent vertices have the same color.
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int node, vector<int> &color, vector<vector<int>> &graph, int n, int c) {
    for (int k = 0; k < n; k++) {
        if (graph[node][k] == 1 && color[k] == c)
            return false;
    }
    return true;
}

bool solve(int node, vector<int> &color, int m, int n, vector<vector<int>> &graph) {
    if (node == n) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, color, graph, n, c)) {
            color[node] = c;
            if (solve(node + 1, color, m, n, graph)) return true;
            color[node] = 0; // backtrack
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>> &graph, int m, int n) {
    vector<int> color(n, 0);
    return solve(0, color, m, n, graph);
}

int main() {
int N = 4; // Number of nodes
int M = 3; // Max colors

vector<vector<int>> graph = {
    {0, 1, 1, 1},
    {1, 0, 1, 1},
    {1, 1, 0, 0},
    {1, 1, 0, 0}
};

if (graphColoring(graph, M, N))
    cout << "YES\n";
else
    cout << "NO\n";

return 0;
}

//time: O(M^N * N^2)
//space: O(N)
