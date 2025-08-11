//Given a rows x cols binary matrix filled with 0's and 1's, find the largest 
//rectangle containing only 1's and return its area.
#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxArea=0;
        int n = heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()? -1: st.top();
                maxArea = max(maxArea,(nse-pse-1)*heights[element]);
            }
            st.push(i);
        }
       
       while(!st.empty()){
        int nse = n;
        int element = st.top();
        st.pop();
        int pse = st.empty()? -1:st.top();
        maxArea = max(maxArea, (nse-pse-1)*heights[element]);
       }
       return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea =0;
        vector<vector<int>>heights(n,vector<int>(m));
       for (int j=0;j<m;j++) {
            for (int i=0;i<n;i++) {
                if (matrix[i][j]=='1')
                    heights[i][j] = (i==0?1:heights[i-1][j]+1);
                else
                    heights[i][j] = 0;
            }
        }

        for(int i=0;i<n;i++){
            maxArea = max(maxArea,largestRectangleArea(heights[i]));
        }
        return maxArea;
    }

int main() {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    int answer = maximalRectangle(matrix);
    cout << "The area of the largest rectangle containing only 1's is: " << answer << endl;
    return 0;
}

//time: O(n*m)
//space: O(n*m) for heights matrix


