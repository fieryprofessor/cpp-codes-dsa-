//Given an integer array nums and an integer k, return the k most frequent 
//elements. You may return the answer in any order.
#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        priority_queue<pair<int, int>> maxHeap;

        for (auto &it : freq) {
            int num = it.first;
            int count = it.second;
            maxHeap.push({count, num});
        }

        vector<int> result;
        while (k-- && !maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
}

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> ans = topKFrequent(nums,k);
    for(int ele: ans){
        cout<<ele<<" ";
    }
    return 0;
}

//time:O(n log n)
//space:O(n)