//Given an array of integers heights representing the histogram's bar height where
//the width of each bar is 1, return the area of the largest rectangle in the 
//histogram.
#include<bits/stdc++.h>
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

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << endl;
    return 0;
}

//time: O(n)
//space: O(n)