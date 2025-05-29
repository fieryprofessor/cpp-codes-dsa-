//Count the number of inversions in the array where an inversion is defined as:
// a pair(i,j)such that i<j and a[i]>a[j]
#include<bits/stdc++.h>
using namespace std;

int Merge(vector<int>&v,int low,int mid,int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    int invCount=0;
    while(left<=mid && right<=high){
        if(v[left]<=v[right])
        temp.push_back(v[left++]);
        else{
            temp.push_back(v[right++]);
            invCount+=(mid-left+1);
        }
        
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
    return invCount;
}

int MergeSort(vector<int>&v,int low , int high){
    int invCount=0;
        if(low>=high)
        return 0;
        
        int mid = (low+high)/2;
        invCount+=MergeSort(v,low,mid);
        invCount+=MergeSort(v,mid+1,high);
        invCount+=Merge(v,low,mid,high); 
        return invCount; 
}


int main(){
    vector<int> v= {8, 4, 2, 1};
    int count = MergeSort(v,0,v.size()-1);
    cout<<count<<endl;
    return 0;
}

//time: O(nlogn)
//space: O(n)