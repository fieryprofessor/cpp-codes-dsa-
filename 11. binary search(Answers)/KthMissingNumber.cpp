//Given an array arr of positive integers sorted in a strictly increasing order, 
//and an integer k.
//Return the kth positive integer that is missing from this array.
#include<bits/stdc++.h>
using namespace std;

 int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low =0;
        int high= n-1;
        while(low<=high){
            int mid = low+((high-low)/2);
            int missing = arr[mid]-(mid+1);
            if(missing<k){
                low=mid+1;
            }else{
                high = mid-1;
            }
        }
        return low+k;
    }

int main(){
    vector<int>nums = {2,3,4,7,11};
    int k = 5;
    int number = findKthPositive(nums,k);
    cout<<number<<endl;
    return 0;
}

//time:O(logn)
//space:O(1)
//missing = arr[high]-(high+1)
//ans = arr[high]+more
//more = k-missing = k-(arr[high]-high-1)= k-arr[high]+high+1
//ans= arr[high]+k-arr[high]+high+1 = k+high+1
//low=high+1
//therefore ans = low+k