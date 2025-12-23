// There are n cities. Some of them are connected, while some are not.
// If city a is connected directly with city b, and city b is connected directly 
// with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no 
// other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the 
// ith city and the jth city are directly connected, and isConnected[i][j] = 0 
// otherwise.Return the total number of provinces.

#include <bits/stdc++.h>
using namespace std;

void dfs(int city, vector<vector<int>>& isConnected, vector<int>& visited) {
    visited[city] = 1;

    for (int i = 0; i < isConnected.size(); i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(i, isConnected, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> visited(n, 0);
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            provinces++;
            dfs(i, isConnected, visited);
        }
    }
    return provinces;
}

int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    cout << "Number of Provinces: "
         << findCircleNum(isConnected) << endl;

    return 0;
}

//time: O(n^2)
//space: O(n) for visited array and O(n) for recursion stack