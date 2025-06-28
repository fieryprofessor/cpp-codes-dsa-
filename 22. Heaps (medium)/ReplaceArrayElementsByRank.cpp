//Given an array of N integers, the task is to replace each 
//element of the array by its rank in the array.
#include<bits/stdc++.h>
using namespace std;

void replaceWithRank(vector<int>&nums){
    priority_queue<int> maxHeap;
    unordered_map<int, int> rankMap;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        maxHeap.push(nums[i]);
    }

    int rank = n;
    while (!maxHeap.empty()) {
        int ele = maxHeap.top();
        maxHeap.pop();

    if (rankMap.find(ele) == rankMap.end()) {
            rankMap[ele] = rank--;
        }
    }

    for (int i = 0; i < n; i++) {
        nums[i] = rankMap[nums[i]];
    }
}

int main(){
    vector<int> nums = {20, 15, 26, 2, 98, 6};
    for(int ele:nums){
        cout<<ele<<" ";
    }
    cout<<endl;
    replaceWithRank(nums);
    for(int ele:nums){
        cout<<ele<<" ";
    }
    return 0;
}

//time:O(n log n)
//space:O(n)

//Note: the heap approach only give correct answer for unique elements.
// If array contains duplicates then use Sorting+Hashing approach:

// vector<int> arrayRankTransform(vector<int>& arr) {
//         vector<int> sorted = arr;
//         sort(sorted.begin(), sorted.end());
//         unordered_map<int, int> rankMap;
//         int rank = 1;

//         for (int val : sorted) {
//             if (rankMap.find(val) == rankMap.end()) {
//                 rankMap[val] = rank++;
//             }
//         }

//         for (int i = 0; i < arr.size(); i++) {
//             arr[i] = rankMap[arr[i]];
//         }

//         return arr;
//     }