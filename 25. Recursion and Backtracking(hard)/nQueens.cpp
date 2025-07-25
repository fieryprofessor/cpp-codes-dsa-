//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such 
//that no two queens attack each other.
//Given an integer n, return all distinct solutions to the n-queens puzzle. 
//You may return the answer in any order.
//Each solution contains a distinct board configuration of the n-queens' placement, 
//where 'Q' and '.' both indicate a queen and an empty space, respectively.
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string>board, int n){
        //check upper diagonal
        int duprow = row;
        int dupcol = col;

        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        } 

        //check straight left
        col = dupcol;
        row = duprow;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }

        //check lower diagonal
        col = dupcol;
        row = duprow;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);
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