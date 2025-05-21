//Rearrange array elements according to the sign, positive at even places and negatives
//at odd places. arrays does not contain same number of postives and negatives.
#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeElements(vector<int>&v){
    vector<int>pos,neg;
    for(int ele:v){
        if(ele>0)
        pos.push_back(ele);
        else
        neg.push_back(ele);
    }
    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            v[i*2]=pos[i];
            v[i*2+1]=neg[i];
        }
        int idx = neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            v[idx]=pos[i];
            idx++;
        }
    }else{
        for(int i=0;i<pos.size();i++){
            v[i*2]=pos[i];
            v[i*2+1]=neg[i];
        }
        int idx = pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            v[idx]=neg[i];
            idx++;
        }
    }
    return v;
}

int main(){
    vector<int>v={-1,2,3,4,-3,1};
    vector<int>ans = rearrangeElements(v);
    for(int ele :ans){
        cout<<ele<<" ";
    }
    return 0;
}
//time: O(2n)
//space:O(n)