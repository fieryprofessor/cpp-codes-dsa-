//The next greater element of some element x in an array is the first greater element that
//is to the right of x in the same array. You are given two distinct 0-indexed integer 
//arrays nums1 and nums2, where nums1 is a subset of nums2. For each 0 <= i < nums1.length,
//find the index j such that nums1[i] == nums2[j] and determine the next greater element 
//of nums2[j] in nums2. If there is no next greater element, then the answer for this query
//is -1. Return an array ans of length nums1.length such that ans[i] is the next greater 
//element as described above.
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ngeMap;
        stack<int>st;

        for(int num : nums2){
            while(!st.empty() && num>st.top()){
                ngeMap[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        while(!st.empty()){
            ngeMap[st.top()] = -1;
            st.pop();
        }

        vector<int> result;
        for(int num: nums1){
            result.push_back(ngeMap[num]);
        }

        return result;
    }

int main(){
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    vector<int> result = nextGreaterElement(nums1, nums2);
    for(int num : result){
        cout << num << " ";
    }
    return 0;
}

//time: O(n + m) where n is the size of nums1 and m is the size of nums2
//space: O(n + m) for the map and stack used