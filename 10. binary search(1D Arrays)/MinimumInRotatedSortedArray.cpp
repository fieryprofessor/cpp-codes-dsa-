//Find the minimum element of the rotated sorted array.
#include<bits/stdc++.h>
using namespace std;

int MinimumElementInRotatedSortedArray(vector<int>&v){
    int low = 0;
    int high = v.size()-1;
    
    while(low<high){
        int mid = (low+high)/2;
        if(v[mid]>v[high]){
            low=mid+1;
        }else{
            high = mid;
        } 
    }
    return v[low];
}

int main(){
    vector<int>v={7,8,9,1,2,3,4,5,6};
    int minEle = MinimumElementInRotatedSortedArray(v);
    cout<<minEle<<endl;
    return 0;
}

//time:O(logn)
//space:O(1)
//minimum element always lies in the unsorted part of the array.
//the index of the minimum element gives how many times the array is rotated.