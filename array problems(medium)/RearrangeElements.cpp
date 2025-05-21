//Rearrange array elements according to the sign, positive at even places and negatives
//at odd places. arrays contains same number of postives and negatives.
#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeElements(vector<int>&v){
    vector<int>ans(v.size());
    int pos=0,neg=1;
    for(int i=0;i<v.size();i++){
        if(v[i]>0){
            ans[pos]=v[i];
            pos+=2;
        }else{
            ans[neg]=v[i];
            neg+=2;
        }
    }
    return ans;
}

int main(){
    vector<int>v={3,1,-2,-5,2,-4};
    vector<int>ans = rearrangeElements(v);
    for(int ele :ans){
        cout<<ele<<" ";
    }
    return 0;
}
//time: O(n)
//space:O(n)