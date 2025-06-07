//A peak element in a 2D grid is an element that is strictly greater than all of its 
//adjacent neighbors to the left, right, top, and bottom.
//Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any 
//peak element mat[i][j] and return the length 2 array [i,j].
//You may assume that the entire matrix is surrounded by an outer perimeter with the 
//value -1 in each cell.
//You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
#include<bits/stdc++.h>
using namespace std;

 vector<int> findPeakGrid(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        int low = 0;
        int high = m-1;
        while(low<=high){
            int mid = (low+high)/2;
            
            int maxEle=-1;
            int maxIndex =-1;
            for(int i=0;i<n;i++){
                if(v[i][mid]>maxEle){
                    maxEle=v[i][mid];
                    maxIndex = i;
                }
            }
            int left = mid-1>=0?v[maxIndex][mid-1]:-1;
            int right = mid+1<m?v[maxIndex][mid+1]:-1;

            if(v[maxIndex][mid]>left && v[maxIndex][mid]>right)
            return {maxIndex,mid};
            else if(v[maxIndex][mid]<left)
            high = mid-1;
            else
            low= mid+1;
        }
        return {-1,-1};
    }

int main(){
    vector<vector<int>>mat = {{1,4},{3,2}};
    vector<int>ans = findPeakGrid(mat);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}

//time: O(nlogm)
//sapce:O(1)