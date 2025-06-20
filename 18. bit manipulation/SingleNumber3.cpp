//Given an integer array nums, in which exactly two elements appear only once 
//and all the other elements appear exactly twice.
//Find the two elements that appear only once. You can return the answer in any order.
#include<bits/stdc++.h>
using namespace std;

 vector<int> singleNumber3(vector<int>& nums) {
        int xorAll =0;
        for(int i=0;i<nums.size();i++){
            xorAll = xorAll^nums[i];
        }

        int idx = 0;
        while((xorAll&1)==0){
            xorAll= xorAll>>1;
            idx++;
        }

        int groupZero =0;
        int groupOne = 0;
        for(int ele : nums){
            if((ele&(1<<idx))==0)
            groupZero = groupZero^ele;
            else
            groupOne = groupOne^ele;
        }
        return {groupZero,groupOne};
    }

int main(){
    vector<int> v = {1,2,1,3,2,5};
    vector<int> answer = singleNumber3(v);
    cout<<answer[0]<<" "<<answer[1]<<endl;
    return 0;
}

//time:O(n)
//space:O(1)