//pair
#include<bits/stdc++.h>
using namespace std;

int main(){
    //pair is used to store two values in a variable.
    pair<int,int>p = {1,3};
    cout<<p.first<<" "<<p.second<<endl;
    //we can also nest pairs
    pair<int,pair<int,int>> np = {1,{2,3}};
    cout<<np.first<<" "<<np.second.first<<" "<<np.second.second<<endl;
    //we can create an array of pairs
    pair<int,int> arr[] = {{1,2},{3,4},{5,6},{7,8}};
    cout<<arr[1].first<<" "<<arr[2].second<<endl;
    return 0;
}