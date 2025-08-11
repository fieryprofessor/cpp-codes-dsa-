//You are given an array of integers nums, there is a sliding window of size k which 
//is moving from the very left of the array to the very right. You can only see the k 
//numbers in the window. Each time the sliding window moves right by one position.
//Return the max sliding window.
#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front()<=i-k)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }

int main(){
    vector<int>nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums,k);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}

//time: O(n)
//space: O(k)