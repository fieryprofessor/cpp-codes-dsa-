//left rotate an array by d places.
#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>&v,int low , int high){
    while(low<=high){
        swap(v[low],v[high]);
        low++;
        high--;
    }
}

int main(){
    vector<int>v={1,2,3,4,5,6,7};
    int d;
    cin>>d;

    d = d % v.size();

    reverse(v,0,d-1);
    reverse(v,d,v.size()-1);
    reverse(v,0,v.size()-1);

    for(int ele:v){
        cout<<ele<<" ";
    }
    return 0;
}

//time: O(2n)
//space: O(1)