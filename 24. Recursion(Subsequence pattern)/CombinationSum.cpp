//Given an array of distinct integers candidates and a target integer target, 
//return a list of all unique combinations of candidates where the chosen numbers 
//sum to target. You may return the combinations in any order.
//The same number may be chosen from candidates an unlimited number of times. 
//Two combinations are unique if the frequency of at least one of the chosen numbers 
//is different.
//The test cases are generated such that the number of unique combinations that 
//sum up to target is less than 150 combinations for the given input.
#include<bits/stdc++.h>
using namespace std;

void findCombination(int idx, int target,vector<int>&candidates, vector<vector<int>>&ans , vector<int>&ds){
        if(idx==candidates.size()){
            if(target==0)
            ans.push_back(ds);
            return;
        }
        //pick up
        if(candidates[idx]<=target){
            ds.push_back(candidates[idx]);
            findCombination(idx,target-candidates[idx],candidates,ans,ds);
            ds.pop_back();
        }
        //not pick
        findCombination(idx+1,target,candidates,ans,ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0,target,candidates,ans,ds);
        return ans;
    }

int main(){
    vector<int>candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = combinationSum(candidates,target);
      for(const auto& row : ans) {
        for(int num : row) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//time: O(2^n) where n is the number of candidates.
//space: O(n) for the recursion stack and the answer storage.
