//Given an array of intervals where intervals[i] = [starti, endi], merge all 
//overlapping intervals, and return an array of the non-overlapping intervals 
//that cover all the intervals in the input.
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end){
                end = max(intervals[i][1],end);
            }else{
                ans.push_back({start,end});
                start= intervals[i][0];
                end = intervals[i][1];
            } 
        }
        ans.push_back({start,end});
        return ans;
    }

int main(){
    vector<vector<int>>v={{1,3},{2,6},{8,10},{15,18}};
     vector<vector<int>>ans= merge(v);
    for(auto v :ans){
        cout<<"["<<v[0]<<","<<v[1]<<"]"<<" ";

    }
    return 0;
}

//time:O(nlogn)
//space:O(n) for storing the output

