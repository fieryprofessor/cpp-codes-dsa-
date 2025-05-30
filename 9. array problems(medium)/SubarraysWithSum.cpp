//Find the number of subarrays with the given sum
#include<bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int>&v,int k){
    int count =0;
    int sum= 0;
    map<int,int>PrefixSumMap;
    PrefixSumMap[0]=1;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        int rem = sum-k;
        count+=PrefixSumMap[rem];
        PrefixSumMap[sum]++;   
    }
    return count;
}

int main(){
    vector<int>v={1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    int count = numberOfSubarrays(v,k);
    cout<<count<<endl;
    return 0;
}

//time: O(nlogn)
//space:O(n)