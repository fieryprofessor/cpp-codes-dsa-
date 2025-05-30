//Merge Sort - keep on dividing the array into smaller units and then combines them.
#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int>&v,int low,int mid,int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(v[left]<=v[right])
        temp.push_back(v[left++]);
        else
        temp.push_back(v[right++]);
    }
    while(left<=mid){
        temp.push_back(v[left++]);
    }
    while(right<=high){
        temp.push_back(v[right++]);
    }
    for(int i=low;i<=high;i++){
        v[i]=temp[i-low];
    }
}

void MergeSort(vector<int>&v,int low , int high){
        if(low>=high)
        return;
        
        int mid = (low+high)/2;
        MergeSort(v,low,mid);
        MergeSort(v,mid+1,high);
        Merge(v,low,mid,high);  
}

int main(){
    vector<int>v={4,2,5,1,3};
    int n = v.size();
    MergeSort(v,0,n-1);
    for(int ele: v){
        cout<<ele<<" ";
    }
    return 0;
}

/*
 * Time Complexity = O(n.log(n))
 * Space Complexity = O(n)
 * Stable Sorting = Yes
 */