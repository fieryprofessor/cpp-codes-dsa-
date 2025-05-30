//You have a set of integers s, which originally contains all the numbers from 1 to n.
// Unfortunately, due to some error, one of the numbers in s got duplicated to another number
// in the set, which results in repetition of one number and loss of another number.
//You are given an integer array nums representing the data status of this set after the error.
//Find the number that occurs twice and the number that is missing and return
// them in the form of an array.
// In Short find the Duplicate number and the Missing number in the array.
#include<bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int totalSum = (n*(n+1))/2;
        int arraySum= accumulate(nums.begin(),nums.end(),0);
        int duplicate = -1;
        for(auto it:m){
            if(m[it.first]==2){
                ans.push_back(it.first);
                duplicate = it.first;
            }
            
        }
        int missingNo = totalSum - (arraySum-duplicate);
        ans.push_back(missingNo);
        return ans;
    }
    //time:O(nlogn) , can reduce to O(2n)if we take hash array instead of map.
    //space:O(n)

    vector<int> findErrorNumsMath(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        long long x=0,y=0;
        //x=duplicate , y = missing
        long long arrayTotalSum =0;
        long long arraySquareSum=0;
        for(int ele:nums){
            arrayTotalSum+=ele;
            arraySquareSum+=(1LL*ele*ele);
        }
        long long totalSum =(1LL*n*(n+1))/2;
        long long squareSum=(1LL*n*(n+1)*((2*n)+1))/6;
        long long xMinusy =  arrayTotalSum - totalSum;
        long long xSquareMinusySquare = arraySquareSum -squareSum;
        long long xPlusy= xSquareMinusySquare/xMinusy;
        x= (xPlusy+xMinusy)/2;
        y=xPlusy-x;
        ans.push_back((int)x);
        ans.push_back((int)y);
        return ans;
    }
    //time:O(n)
    //space:O(1)

     vector<int> findErrorNumsXor(vector<int>& nums) {
        int n = nums.size();
        int missing=0,duplicate=0;
        int idx=0;
        int xr=0;
        for(int i=0;i<n;i++){
            xr^=nums[i];
            xr^=(i+1);
        }
        while(1){
            if((xr&(1<<idx))!=0)break;
            idx++;
        }

        for(int ele:nums){
            if((ele&(1<<idx))==0)
            duplicate^=ele;
            else
            missing^=ele;
        }
        for(int i=1;i<=n;i++){
            if((i&(1<<idx))==0)
            duplicate^=i;
            else
            missing^=i;
        }
        for (int ele : nums) {
            if (ele == duplicate)
                return {duplicate, missing};
        }
        return {missing,duplicate};
    }
    //time:O(n)
    //space:O(1)

int main(){
    vector<int>nums = {1,2,2,4};
    vector<int>ans = findErrorNums(nums);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    vector<int>ans2 = findErrorNumsMath(nums);
    cout<<ans2[0]<<" "<<ans2[1]<<endl;
    vector<int>ans3 = findErrorNumsXor(nums);
    cout<<ans3[0]<<" "<<ans3[1]<<endl;
    return 0;
}