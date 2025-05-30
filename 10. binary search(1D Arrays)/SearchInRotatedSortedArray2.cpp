//Search the target in the rotated sorted array. (Array have duplicates)
#include<bits/stdc++.h>
using namespace std;

bool SearchInRotatedSortedArray2(vector<int>&v, int target){
    int low = 0;
    int high = v.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(v[mid]==target)return true;

        if(v[low]==v[mid] && v[mid]==v[high]){
            low++;
            high--;
        }
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
    return false;
}

int main(){
    vector<int>v={2,5,6,0,0,1,2};
    int target= 0;
    bool isPresent = SearchInRotatedSortedArray2(v,target);
    cout<<isPresent<<endl;
    return 0;
}

//time:O(logn)
//spce:O(1)
