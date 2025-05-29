//Search the target in the rotated sorted array. (all Elements are Unique)
#include<bits/stdc++.h>
using namespace std;

int SearchInRotatedSortedArray(vector<int>&v, int target){
    int low = 0;
    int high = v.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(v[mid]==target)return mid;
        else if(v[mid]<v[low]){
            if(target>v[mid] && target<=v[high])
            low=mid+1;
            else
            high = mid-1;
        }else{
            if(target>=v[low] && target<v[mid])
            high = mid-1;
            else
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int>v={7,8,9,1,2,3,4,5,6};
    int target= 1;
    int index = SearchInRotatedSortedArray(v,target);
    cout<<index<<endl;
    return 0;
}

//time:O(logn)
//spce:O(1)