//Given an integer array nums that may contain duplicates,return all possible subsets
//(the power set).The solution set must not contain duplicate subsets.
#include <bits/stdc++.h>
using namespace std;

void findSubsets(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
    ans.push_back(ds);  // Store current subset

    for (int i = ind; i < nums.size(); i++) {
        // Skip duplicates
        if (i != ind && nums[i] == nums[i - 1]) continue;

        ds.push_back(nums[i]);
        findSubsets(i + 1, nums, ds, ans);  // Recursive call
        ds.pop_back();  // Backtrack
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;

    sort(nums.begin(), nums.end());  // Sort to bring duplicates together
    findSubsets(0, nums, ds, ans);

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2};  // Input
    vector<vector<int>> result = subsetsWithDup(nums);

    for (const auto& subset : result) {
        for (int ele : subset) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
//time: O(2^n) where n is the size of the input array.
//space: O(n) for the recursion stack.
//Note: The sorting step ensures that duplicates are adjacent, allowing us to skip them efficiently.    