//Given an array nums of distinct integers, return all the possible permutations.
// You can return the answer in any order.
//This is approach 2 of the permutation problem using backtracking.
#include<bits/stdc++.h>
using namespace std;

void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans) {
    if (index == nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]); // backtrack
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    recurPermute(0, nums, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);

    for (const auto& row : result) {
        for (int val : row){
            cout << val << " ";
        }
        cout<<endl;
    }

    return 0;
}

//time: O(n!*n)
//space: O(n) for recursion stack