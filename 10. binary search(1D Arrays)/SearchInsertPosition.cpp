//Given a sorted array of distinct integers and a target value, return the index if the 
//target is found. If not, return the index where it would be if it were inserted in order.
#include<bits/stdc++.h>
using namespace std;

int SearchInsertPosition(vector<int>&v, int target){
    int low = 0;
    int high = v.size()-1;
    
    while(low<=high){
        int mid = (low+high)/2;
        if(v[mid]>=target){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    vector<int>v={1,3,5,6};
    int target= 4;
    int index = SearchInsertPosition(v,target);
    cout<<index<<endl;
    return 0;
}

//time:O(logn)
//space:O(1)