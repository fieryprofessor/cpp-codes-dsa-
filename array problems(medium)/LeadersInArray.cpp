//Find all the leaders in the array (elements whose right side elements are less than itself)
#include<bits/stdc++.h>
using namespace std;

vector<int>leadersInArray(vector<int>&v){
    int leader = INT_MIN;
    vector<int>ans;
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]>leader){
            leader=v[i];
            ans.push_back(leader);
        }
    }
    return ans;
}

int main(){
    vector<int>v={10,22,12,3,0,6};
    vector<int>ans = leadersInArray(v);
    for(int ele:ans){
        cout<<ele<<" ";
    }
    return 0;
}

//time:O(n)
//space:O(n)