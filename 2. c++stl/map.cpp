//map
#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,int> m; // stores as key value pair , and they can be of any data type.
    //keys are in sorted order
    m[1]= 2;
    m.insert({2,4});

    for(auto it : m)
    cout<<it.first<<" "<<it.second<<endl;

    // multimap - duplicate keys in sorted order
    multimap<int,int> m2;

    //unorderedmap - unique keys but not in sorted order.
    unordered_map<int,int> m3;
    
    return 0;
}