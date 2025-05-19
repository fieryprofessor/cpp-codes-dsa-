//Maximum subarray sum - Kadane's Algorithm (it handles both positive and negative numbers)
//This time return the maximum sum subarray.
#include<bits/stdc++.h>
using namespace std;

vector<int> kadaneAlgo(vector<int>&v){
   int maxSum=INT_MIN;
   int prefixSum =0;
   int start = 0,end =0,tempStart=0;
   for(int i=0;i<v.size();i++){
        prefixSum+=v[i];

        if(prefixSum>=maxSum){
            maxSum = prefixSum;
            start= tempStart;
            end = i;
        }
        
        if(prefixSum<0){
            prefixSum =0;
            tempStart = i+1;
        }
   }
   vector<int>ans;
   for(int i=start;i<=end;i++){
        ans.push_back(v[i]);
   }
   return ans;
}

int main(){
    vector<int>v = {-2,-3,4,-1,-2,1,5,-3};
    vector<int> ans = kadaneAlgo(v);
    for(int ele :ans){
        cout<<ele<<" ";
    }
    return 0;
}

//time:O(n)
//space:O(1)