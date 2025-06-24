//Given an integer array nums and an integer k, return the number of good subarrays of nums.
//A good array is an array where the number of different integers in that array is exactly k.
#include<bits/stdc++.h>
using namespace std;

//no.of subarrays with distinct elements less than equal to k.
int subArrayCount(vector<int>v, int k){
    int n = v.size();
    int c = 0;
    int start =0;
    unordered_map<int,int>m;
    for(int end = 0;end < n; end++){
        m[v[end]]++;

        while(m.size()>k){
            m[v[start]]--;
            if(m[v[start]]==0)
            m.erase(v[start]);
            start++;
        }

        c += (end - start + 1);
    }
    return c;
}

int main(){
    vector<int>nums = {1,2,1,2,3};
    int k = 2;
    int count = subArrayCount(nums,k)-subArrayCount(nums,k-1);
    cout<<count<<endl;
    return 0;
}

//time:O(n)
//space:O(k) k = no. of distinct elements