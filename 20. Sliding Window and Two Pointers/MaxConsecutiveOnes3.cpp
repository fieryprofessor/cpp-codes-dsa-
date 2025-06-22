//Given a binary array nums and an integer k, return the maximum number of consecutive 1's
//in the array if you can flip at most k 0's.
#include<bits/stdc++.h>
using namespace std;

 int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int maxLen = 0;
    int start = 0;
    int zeros = 0;
    for (int end = 0; end < n; end++) {
        if(nums[end]==0)
        zeros++;

        while(zeros>k){
            if (nums[start] == 0)
            zeros--;
            start++;
        }
        maxLen = max(maxLen, end - start + 1);
    }
        return maxLen;
    }

int main(){
    vector<int>nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int len = longestOnes(nums,k);
    cout<<len<<endl;
    return 0;
}

//time:O(n)
//space:O(1)