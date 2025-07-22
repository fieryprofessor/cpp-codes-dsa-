//Given a collection of candidate numbers (candidates) and a target number (target),
//find all unique combinations in candidates where the candidate numbers sum to target.
//Each number in candidates may only be used once in the combination.
//Note: The solution set must not contain duplicate combinations.
#include<bits/stdc++.h>
using namespace std;

void findCombination(int idx, int target, vector<int>&candidates, vector<vector<int>>&ans, vector<int>&ds) {
        if(target==0){
            ans.push_back(ds);
            return;
        }

        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            findCombination(i+1,target-candidates[i],candidates,ans,ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0,target,candidates,ans,ds);
        return ans;
    }

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(candidates,target);
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