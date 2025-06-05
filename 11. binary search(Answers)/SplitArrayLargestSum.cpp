//Given an integer array nums and an integer k, split nums into k non-empty 
//subarrays such that the largest sum of any subarray is minimized.
//Return the minimized largest sum of the split.
//A subarray is a contiguous part of the array.
// This problem is also known as Painter's Partition.
#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> nums, int mid, int k){
        int subA = 1, currSum = 0;
        for(int ele: nums){
            if(currSum+ele>mid){
                subA++;
                currSum = ele;
                if(subA>k)
                return false;
            }
            else{
                currSum+=ele;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;
        while(low<=high){
            int mid = low+((high-low)/2);
            if(isValid(nums,mid,k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }

    int main(){
        vector<int>nums = {7,2,5,10,8};
        int k = 2;
        int ans = splitArray(nums,k);
        cout<<ans<<endl;
        return 0;
    }

//time:O(nlogsum)
//space:O(1)