//You are given an integer array nums. You are initially positioned at the 
//array's first index, and each element in the array represents your maximum 
//jump length at that position.
//Return true if you can reach the last index, or false otherwise.

#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxInd =0;
        for(int i=0;i<n;i++){
            if(i>maxInd)
            return false;
            maxInd = max(maxInd,i+nums[i]);
        }
        return true;
    }

int main(){
    vector<int> nums = {2,3,1,1,4};
    bool res = canJump(nums);
    cout<<res<<endl;
    return 0;
}

//time:O(n)
//space:O(1)