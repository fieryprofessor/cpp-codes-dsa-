//Given an array of intervals intervals where intervals[i] = [starti, endi], 
//return the minimum number of intervals you need to remove to make the rest 
//of the intervals non-overlapping.
//Note that intervals which only touch at a point are non-overlapping. 
//For example, [1, 2] and [2, 3] are non-overlapping.
#include <bits/stdc++.h>
using namespace std;

static bool comp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), comp);
    int count =1;
    int lastEndTime = intervals[0][1];
    int n = intervals.size();
    for(int i=0;i<n;i++){
        if(intervals[i][0]>=lastEndTime){
            count++;
            lastEndTime = intervals[i][1];
        }
    }
    return n-count;
}

int main() {
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout<<eraseOverlapIntervals(intervals);
    return 0;
}

//time: O(nlogn)    
//space: O(1)

