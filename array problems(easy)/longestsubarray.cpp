//give the length of the longest subarray with sum k of the given array.
#include<bits/stdc++.h>
using namespace std;

//this Hashing technique works both for positive+negative elements in the array.
int longestSubarrayLength(vector<int>v,int k){
    map<int ,int>preSumMap;
    int sum =0;
    int maxLen =0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        if(sum==k){
            maxLen = max(maxLen,i+1);
        }
        int rem = sum-k;
        if(preSumMap.find(rem)!= preSumMap.end()){
            int len = i-preSumMap[rem];
            maxLen = max(maxLen,len);
        }
        if(preSumMap.find(sum)== preSumMap.end()){
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}
//Sliding Window Technique useful for postive array elements only 
int longestSubarraySW(vector<int>v,int k){
        int left =0,right=0;
        int sum =0;
        int maxLen = 0;
        while(right<v.size()){
            sum+=v[right];
            if(sum==k){
                maxLen = max(maxLen,right-left+1);
            }
            while(sum>k && left<=right){
                sum-=v[left];
                left++;
            }
            right++;
        }
        return maxLen;
}

int main(){
    vector<int>v={1,2,3,1,1,1,1,4,2,3};
    int k=3;
    int length1 = longestSubarrayLength(v,k);
    cout<<length1<<endl;
    int length2 = longestSubarraySW(v,k);
    cout<<length2<<endl;

    return 0;
}

//Hashing
//time: O(n^2)
//space: O(n)

//Sliding Window
//time:O(n)
//space: O(1)