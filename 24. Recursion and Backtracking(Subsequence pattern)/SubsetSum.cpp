//Given an array nums of n integers, generate all possible subset sums,
//and return them in increasing order.
#include<bits/stdc++.h>
using namespace std;

void subsetSums(int idx, int sum, vector<int>& nums, vector<int>& ans) {
    if (idx == nums.size()) {
        ans.push_back(sum);
        return;
    }

    // Include current element
    subsetSums(idx + 1, sum + nums[idx], nums, ans);

    // Exclude current element
    subsetSums(idx + 1, sum, nums, ans);
}

vector<int> getAllSubsetSums(vector<int>& nums) {
    vector<int> ans;
    subsetSums(0, 0, nums, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> nums = {3, 1, 2};
    vector<int> ans = getAllSubsetSums(nums);
    for (int ele : ans)
     cout << ele << " ";
    return 0;
}

//time: O(2^n) where n is the size of the input array.
//space: O(n) for the recursion stack.
