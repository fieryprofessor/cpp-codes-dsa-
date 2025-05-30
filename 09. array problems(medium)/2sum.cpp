//find two numbers in the array such that they add up to the given sum.
#include<bits/stdc++.h>
using namespace std;

vector<int> get2Sum(vector<int>v,int target){
    map<int,int>m;
    
    for(int i=0;i<v.size();i++){
        int ele = v[i];
        int rem = target - ele;
        if(m.find(rem)!=m.end()){
            return {m[rem],i};
        }
        m[ele]=i;
    }
    return {};
}

int main(){
    vector<int>v = {2,6,5,8,11};
    int target = 14;
    vector<int>ans=get2Sum(v,target);
    for(int ele:ans){
        cout<<ele<<" ";
    }
    return 0;
}

//time:O(n log n)
//space:O(n)