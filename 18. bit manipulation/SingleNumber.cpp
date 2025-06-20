//Given a non-empty array of integers nums, every element 
//appears twice except for one. Find that single one.
#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
        int answer =0;
        for(int ele: nums){
            answer ^= ele;
        }
        return answer;
}

int main(){
    vector<int> v = {4,1,2,1,2};
    int answer = singleNumber(v);
    cout<<answer;
    return 0;
}

//time:O(n)
//space:O(1)