//Maximum subarray sum - Kadane's Algorithm (it handles both positive and negative numbers)
#include<bits/stdc++.h>
using namespace std;

int kadaneAlgo(vector<int>&v){
   int maxSum=INT_MIN;
   int prefixSum =0;
   for(int i=0;i<v.size();i++){
        prefixSum+=v[i];
        maxSum = max(maxSum,prefixSum);

        if(prefixSum<0){
            prefixSum =0;
        }
   }
   return maxSum;
}

int main(){
    vector<int>v = {-2,-3,4,-1,-2,1,5,-3};
    int sum = kadaneAlgo(v);
    cout<<sum<<endl;
    return 0;
}

//time:O(n)
//space:O(1)