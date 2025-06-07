//Find the median of a row wise sorted matrix.
#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& row, int x, int m) {
    int low = 0, high = m;
    while (low < high) {
        int mid = (low + high) / 2;
        if (row[mid] <= x)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int countSmallEqual(vector<vector<int>> &matrix, int n, int m, int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += upperBound(matrix[i], x, m);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;
    n = matrix.size();
    m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }
    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, n, m, mid);
        if (smallEqual <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}


int main(){
    vector<vector<int>> matrix = {
    {1, 3, 5},
    {2, 6, 9},
    {3, 6, 9}
};
    int m = matrix[0].size();
    int n = matrix.size();
    int result = median(matrix, m, n);
    cout<<result<<endl; 
    return 0;
}

//time:O(log(max-min)*n*logm)
//space:O(1)