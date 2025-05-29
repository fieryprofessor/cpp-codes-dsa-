//Given an array of integers nums sorted in non-decreasing order,
// find the starting and ending position of a given target value.
//If target is not found in the array, return [-1, -1].

#include<bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int>&v, int target){
    int low = 0;
    int high = v.size()-1;
    int index=-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(v[mid]==target){
            index = mid;
            high = mid-1;
        }
        else if(v[mid]<target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return index;
}
    int lastOccurence(vector<int>&v, int target){
    int low = 0;
    int high = v.size()-1;
    int index=-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(v[mid]==target){
            index = mid;
            low = mid+1;
        }
        else if(v[mid]<target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return index;
}

int main(){
    vector<int>v={5,7,7,8,8,10};
    int target= 8;
    vector<int>ans;
    ans.push_back(firstOccurence(v,target));
    ans.push_back(lastOccurence(v,target));
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}

//time:O(logn)
//space:O(1)

//to find all the number of occurences of target in a given sorted array just find
// lowerbound and upperbound, the target will occur from lowerbound to upperbound-1 and
// number of occurences = (upperbound-1)-lowerbound
//or simply you can do lastOccurence-firstOccurence

