//You are given a N x N binary matrix maze[][] representing a maze.
//Your task is to find all possible paths for a rat to reach from the top-left corner (0, 0)
//to the bottom-right corner (N-1, N-1) of the maze. The rat can move only in four directions:
// Down (D), Left (L), Right (R), and Up (U).
//A cell with a value 1 means it is open, and the rat can move through it.
//A cell with a value 0 means it is blocked, and the rat cannot enter that cell.
//The rat cannot visit the same cell more than once in a path.
//You need to return all possible paths from (0, 0) to (N-1, N-1) in lexicographical order
//as strings of directions.
#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans,
           string move, vector<vector<int>> &vis, int di[], int dj[]) {
    if (i == n - 1 && j == n - 1) {
        ans.push_back(move);
        return;
    }

    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];

        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n &&
            !vis[nexti][nextj] && a[nexti][nextj] == 1) {
            vis[i][j] = 1;
            solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
            vis[i][j] = 0;
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[] = {+1, 0, 0, -1}; // Down, Left, Right, Up
    int dj[] = {0, -1, 1, 0};

    if (m[0][0] == 1)
        solve(0, 0, m, n, ans, "", vis, di, dj);

    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> result = findPath(maze, n);

    if (result.empty()) {
        cout << "No path found" << endl;
    } else {
        sort(result.begin(), result.end()); // Optional: lexicographical order
        for (const auto &path : result) {
            cout << path << endl;
        }
    }

    return 0;
}

//time: O(4^(N*M)), where N is the number of rows and M is the number of columns in the maze.
//space: O(N*M), for the visited matrix and the recursion stack.
