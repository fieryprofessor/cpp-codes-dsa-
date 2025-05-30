//Find the Maximum Product Subarray
#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxP = INT_MIN;
        int pre =1,suf=1;
        for(int i=0;i<n;i++){
            if(pre==0)pre=1;
            if(suf==0)suf=1;
            pre*=nums[i];
            suf*=nums[n-1-i];
            maxP=max(maxP,max(pre,suf));
        }
        return maxP;
    }

int main(){
    vector<int>v = {2,3,-2,4};
    int p = maxProduct(v);
    cout<<p<<endl;
    return 0;
}

//time:O(n)
//space:O(1)