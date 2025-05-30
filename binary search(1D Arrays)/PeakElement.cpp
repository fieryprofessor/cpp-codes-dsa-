//Find the peak element in the array(Array can have multiple peaks)
#include<bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        int low = 1;
        int high = n-2;
        while(low<=high){
            int mid = low+((high-low)/2);
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            return mid;
            else if(nums[mid]>nums[mid-1])
            low = mid+1;
            else
            high = mid-1;
            }
        return -1;
    }

int main(){
    vector<int> v = {1, 3, 20, 4, 1, 0};
    int index = findPeakElement(v);
    cout<<index<<endl;
    return 0;
}

//time:O(logn)
//space:O(1)