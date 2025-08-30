//You are given a 0-indexed array of integers nums of length n. You are initially
//positioned at index 0.
//Each element nums[i] represents the maximum length of a forward jump 
//from index i. In other words, if you are at index i, you can jump to any 
//index (i + j) where:
//0 <= j <= nums[i] and
//i + j < n
//Return the minimum number of jumps to reach index n - 1. The test cases are
//generated such that you can reach index n - 1.
#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, farthest = 0, end = 0;

        for(int i=0; i<n-1; i++) {
            farthest = max(farthest, i + nums[i]);
            if(i == end) {  
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }

int main(){
    vector<int> nums = {2,3,1,1,4};
    int res = jump(nums);
    cout<<res<<endl;
    return 0;
}

//time:O(n)
//space:O(1)