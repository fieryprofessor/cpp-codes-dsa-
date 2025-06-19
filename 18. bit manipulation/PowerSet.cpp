//Given an array print all the subsets of an array.(Power Set)
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int subsets = 1<<n;
    vector<vector<int>>ans;
    for(int num=0;num<subsets;num++){
        vector<int>temp;
        for(int i=0;i<n;i++){
            if((num&(1<<i))!=0)
            temp.push_back(nums[i]);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    vector<int> v= {1,2,3};
    vector<vector<int>>ans = subsets(v);

     for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//time:O(n*2^n)
//space:O(n*2^n)