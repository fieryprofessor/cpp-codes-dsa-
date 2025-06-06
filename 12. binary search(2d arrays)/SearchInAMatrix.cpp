//Search whether the element is present in the matrix or not.
#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& v, int target) {
        int n = v.size();
        int m = v[0].size();
        int i=0;
        while(i<n){
            int low=0;
            int high=m-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(v[i][mid]==target)
                return true;
                else if(v[i][mid]<target)
                low=mid+1;
                else
                high=mid-1;
            }
            i++;
        }
        return false;
    }
    //time:O(nlogm)
    //space:O(1)

    //if the rows are sorted in increasing order in a continuous manner then use this.
    bool searchMatrixBetter(vector<vector<int>>& v, int target) {
        int n = v.size();
        int m = v[0].size();
        int low=0;
        int high =n*m-1;
        while(low<=high){
            int mid = low+((high-low)/2);
            int row = mid/m;
            int col = mid%m;
            if(v[row][col]==target)
            return true;
            else if(v[row][col]<target)
            low=mid+1;
            else
            high=mid-1;
        }
        return false;
    }

    //time:O(log(mn))
    //space:O(1)

    //most optimal approach using staircase search
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int n = v.size();
        int m = v[0].size();
        int i=0;int j=m-1;
        while(i<n && j>=0){
            if(v[i][j]==target)
            return true;
            else if(v[i][j]>target){
               j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
    //time:O(n+m)
    //space:O(1)

int main(){
    vector<vector<int>>matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    bool isPresent = searchMatrix(matrix,target);
    cout<<isPresent<<endl;
    return 0;
}

