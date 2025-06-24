//Given a binary array nums and an integer goal, return the number of non-empty 
//subarrays with a sum goal.
//A subarray is a contiguous part of the array.
#include<bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
       unordered_map<int, int> m;
       m[0] = 1;
       int count =0;
       int sum =0;
       for(int ele :nums){
        sum+=ele;
        if(m.find(sum-goal)!=m.end()){
            count+= m[sum-goal];
        }
        m[sum]++;
       }
       return count;
}

int main(){
    vector<int>nums = {1,0,1,0,1};
    int goal = 2;
    int answer = numSubarraysWithSum(nums,goal);
    cout<<answer<<endl;
    return 0;
}

//time:O(n)
//space:O(n)