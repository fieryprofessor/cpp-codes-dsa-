//Binary Search on Arrays.
#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int>&v, int target){
    int low = 0;
    int high = v.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(v[mid]==target)return mid;
        else if(v[mid]<target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int>v={1,2,3,4,5,6,7,8};
    int target= 7;
    int index = BinarySearch(v,target);
    cout<<index<<endl;
    return 0;
}

//time:O(logn)
//space:O(1)

//efficient mid to avoid overflow 
//mid= low + ((high-low)/2)