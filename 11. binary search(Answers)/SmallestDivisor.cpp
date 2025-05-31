//Given an array of integers nums and an integer threshold, we will choose a positive
//integer divisor, divide all the array by it, and sum the division's result.
//Find the smallest divisor such that the result mentioned above is less than or
//equal to threshold.
//Each result of the division is rounded to the nearest integer greater than or equal to 
//that element. (For example: 7/3 = 3 and 10/2 = 5).
#include<bits/stdc++.h>
using namespace std;

int isSum(int divisor, vector<int>nums){
        int sum=0;
        for(int ele : nums){
            sum+= ceil(double(ele)/divisor);
        }
        return (int)sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(),nums.end());
        int low=1;
        int high = maxEle;
        int divisor = -1;
        while(low<=high){
            int mid= low+((high-low)/2);
            if(isSum(mid,nums)<=threshold){
                divisor = mid;
                high = mid-1;
            }else{
                low=mid+1;
            }
        }
        return divisor;
    }

int main(){
    vector<int>nums = {1,2,5,9};
    int threshold = 6;
    int divisor = smallestDivisor(nums,threshold);
    cout<<divisor<<endl;
    return 0;
}

//time:O(nlog(MaxElement))
//space:O(1)