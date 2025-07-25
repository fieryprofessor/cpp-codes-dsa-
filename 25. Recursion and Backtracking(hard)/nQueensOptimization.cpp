//This is the optimization of the N-Queens problem using backtracking.
//The idea is to use hashing to keep track of the columns, diagonals, and
//anti-diagonals that are already occupied by queens, which allows us to
//avoid unnecessary checks and speed up the solution.
#include<bits/stdc++.h>
using namespace std;

void solve(int col, vector<string> &board, vector<vector<string>> &ans,
               vector<int> &leftRow,
               vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
        
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 &&
                lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {

                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

                // Backtrack
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        vector<int> leftRow(n, 0),
                    upperDiagonal(2 * n - 1, 0),
                    lowerDiagonal(2 * n - 1, 0);

        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }

    int main(){
    int n;
    n = 4;
    vector<vector<string>> result = solveNQueens(n);
    for(const auto& solution : result) {
        for(const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}

//time: O(n!)
//space: O(n^2) for the board and O(n) for the recursion

    
