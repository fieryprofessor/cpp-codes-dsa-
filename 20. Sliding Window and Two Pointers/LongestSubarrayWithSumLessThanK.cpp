//To find the longest subarray with sum ≤ K, the goal is to return the maximum 
//length of a contiguous subarray whose sum is less than or equal to a given integer K.
#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumAtMostK(vector<int>& nums, long long k) {
    int n = nums.size();
    int maxLen = 0;
    int start = 0;
    long long sum = 0;

    for (int end = 0; end < n; end++) {
        sum += nums[end];

        while (sum > k) {
            sum -= nums[start];
            start++;
        }

        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
}

int main(){
    vector<int> v = {2,5,1,7,10};
    int length = longestSubarrayWithSumAtMostK(v,14);
    cout<<length;
    return 0;
}

//time:O(n)
//space:O(1)

//Note this template is the basic structure of a sliding window problems,
//and many problems can be solved by using this template.