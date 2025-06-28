//Given an integer array nums and an integer k, return the kth largest 
//element in the array.Note that it is the kth largest element in the 
//sorted order, not the kth distinct element.
#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for(int i=0;i<nums.size();i++){
            heap.push(nums[i]);
        }
        int ans = 0;
        for(int i=1;i<=k;i++){
            ans = heap.top();
            heap.pop();
        }
        return ans;
}

int main(){
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    int answer = findKthLargest(nums,k);
    cout<<answer<<endl;
    return 0;
}

//time:O(n log n)
//space: O(n)