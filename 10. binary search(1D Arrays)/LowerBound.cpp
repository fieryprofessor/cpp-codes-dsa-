//Lower Bound of a target - smallest index such that v[index]>=target.
#include<bits/stdc++.h>
using namespace std;

int BinarySearchLowerBound(vector<int>&v, int target){
    int low = 0;
    int high = v.size()-1;
    int index =-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(v[mid]==target){
            index = mid;
            high = mid-1;
        }
        else if(v[mid]<target){
            low = mid+1;
        }else{
            index = mid;
            high = mid-1;
        }
    }
    return index;
}

int main(){
    vector<int>v={1, 2, 4, 4, 4, 5, 6, 8, 10};
    int target= 4;
    int index = BinarySearchLowerBound(v,target);
    cout<<index<<endl;
    return 0;
}

//time:O(logn)
//space:O(1)

