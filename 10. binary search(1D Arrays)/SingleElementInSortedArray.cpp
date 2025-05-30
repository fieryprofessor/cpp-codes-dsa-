//Find the Single Element in the Sorted Array , rest all elements have duplicates.
#include<bits/stdc++.h>
using namespace std;

int SingleElement(vector<int>&v){
    int n = v.size()-1;
    int low = 0;
    int high = v.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(mid==0 && v[mid]!=v[mid+1])
                return v[mid];
        if(mid==n-1 && v[mid]!=v[mid-1])
            return v[mid];

        if(v[mid]!=v[mid-1] && v[mid]!=v[mid+1])
        return v[mid];

        if(mid%2==0){
            if(v[mid]==v[mid-1])
            high= mid-1;
            else
            low=mid+1;
        }else{
            if(v[mid]==v[mid-1])
            low=mid+1;
            else
            high= mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int>v={1,1,2,3,3,4,4,8,8};
    int element = SingleElement(v);
    cout<<element<<endl;
    return 0;
}

//time:O(logn)
//space:O(1)

//(even,odd)-> single element is in right
//(odd,even)-> single element is in left
