//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
// and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
//Merge nums1 and nums2 into a single array sorted in non-decreasing order.
//nums1 has a length of m + n, where the first m elements denote the elements that should be 
//merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>=nums2[j]){
                swap(nums1[i],nums1[k]);
                k--;
                i--;
            }else{
                swap(nums1[k],nums2[j]);
                k--;
                j--;
            }
        }
        while(j>=0){
            swap(nums1[k],nums2[j]);
            k--;
            j--;
        }
    }

int main(){
    vector<int>nums1 = {1,2,3,0,0,0};
    vector<int>nums2 = {2,5,6};
    int m = nums1.size()-nums2.size();
    int n = nums2.size();

    merge(nums1,m,nums2,n);

    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }

    return 0;
}

//time:O(m+n)
//space:O(1)