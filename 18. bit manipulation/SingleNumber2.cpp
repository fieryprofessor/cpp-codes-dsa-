//Given an integer array nums where every element appears three times except for one,
//which appears exactly once. Find the single element and return it.
#include<bits/stdc++.h>
using namespace std;

int singleNumber2(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
        for(int i=0;i<32;i++){
            int count =0;
            for(int j=0;j<n;j++){
                if((nums[j]&(1<<i))!=0)
                count++;
            }
            if(count%3==1)
            ans = ans | (1<<i);
        }
        return ans;
}
//time:O(32n)
//space:O(1)

int singleNumber2Optimal(vector<int>& nums){
    int ones = 0;
    int twos = 0;
    for(int ele: nums){
        ones = (ele^ones) & ~twos;
        twos = (ele^twos) & ~ones;
    }
    return ones;
}
//time:O(n)
//space:O(1)

int main(){
    vector<int> v = {0,1,0,1,0,1,99};
    int answer = singleNumber2(v);
    cout<<answer<<endl;
    int answer2 = singleNumber2Optimal(v);
    cout<<answer2;
    return 0;
}

