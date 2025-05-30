//Find the majority element in the array. Moore's Voting Algorithm
#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>&v){
   int freq = 0 , ans=0;
   for(int i=0;i<v.size();i++){
        if(freq==0){
            ans=v[i];
        }
        
        if(v[i]==ans){
            freq++;
        }else{
            freq--;
        }
   }
   return ans;
}

int main(){
    vector<int>v = {2,2,3,3,1,2,2};
    int ele = majorityElement(v);
    cout<<ele<<endl;
    return 0;
}

//time:O(n)
//space:O(1)