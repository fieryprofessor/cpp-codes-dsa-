//Given an array of integers nums and an integer k. A continuous subarray is called
//nice if there are k odd numbers on it.
//Return the number of nice sub-arrays.
#include<bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int count =0;
        int oddSum = 0;
        for(int ele :nums){
            if(ele%2!=0)
            oddSum++;
            if(m.find(oddSum-k)!=m.end()){
                count+= m[oddSum-k];
            }
            m[oddSum]++;
        }
        return count;
}

int main(){
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    int count = numberOfSubarrays(nums,k);
    cout<<count<<endl;
    return 0;
}

//time:O(n)
//space:O(n)