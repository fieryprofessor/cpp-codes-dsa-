//left rotate an array by one place.
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={1,2,3,4,5};
    int first = v[0];
    for(int i=1;i<v.size();i++){
        v[i-1]=v[i];
    }
    v[v.size()-1]=first;
    for(int ele:v){
        cout<<ele<<" ";
    }
    return 0;
}

//time: O(n)