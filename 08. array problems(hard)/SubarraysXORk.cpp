//Count the number of subarrays with xor value equal to k.
#include<bits/stdc++.h>
using namespace std;

int subarrayWithXork(vector<int>&v,int &k){
    int xr=0;
    map<int,int>m;
    m[xr]++;
    int c=0;
    for(int i=0;i<v.size();i++){
        xr^=v[i];
        int x = xr^k;
        if(m.find(x)!=m.end())
        c+=m[x];
        m[xr]++;
    }
    return c;
}

int main(){
    vector<int>v={4,2,2,6,4};
    int k = 6;
    int count = subarrayWithXork(v,k);
    cout<<count<<endl;
    return 0;
}

//time:O(n)
//space:O(n)