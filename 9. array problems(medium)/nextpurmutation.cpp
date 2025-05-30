//find the next permutation of the given array.
#include<bits/stdc++.h>
using namespace std;

void nextPurmutation(vector<int>&v){
    //first finding breakpoint index.
    int breakPoint = -1;
    for(int i=v.size()-2;i>=0;i--){
        if(v[i]<v[i+1]){
            breakPoint = i;
            break;
        }
    }
    if(breakPoint==-1){
        reverse(v.begin(),v.end());
        return;
    }
    //finding the minimum element that is just greater than breakpoint element and swaping it
    //with breakpoint element.
    for(int i=v.size()-1;i>breakPoint;i--){
        if(v[i]>v[breakPoint]){
            swap(v[i],v[breakPoint]);
            break;
        }
    }
    //reversing all the elements after breakPoint index.
    reverse(v.begin()+breakPoint+1,v.end());
}

int main(){
    vector<int>v={4,5,1,6,2};
    nextPurmutation(v);
    for(int ele:v){
        cout<<ele<<" ";
    }
    return 0;
}

//time: O(3n)
//space: O(1)