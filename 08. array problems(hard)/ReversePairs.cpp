//Reverse all Pairs in the array where a pair means
//(i,j) such that i<j and a[i]>2*a[j]
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

int CountPairs(vector<int>&v, int low, int mid, int high){
    int count=0;
    int right = mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && v[i]>2*v[right])right++;
        count+=(right-(mid+1));
    }
    return count;
}

int MergeSort(vector<int>&v,int low , int high){
    int count=0;
        if(low>=high)
        return count;
        
        int mid = (low+high)/2;
        count+=MergeSort(v,low,mid);
        count+=MergeSort(v,mid+1,high);
        count+=CountPairs(v,low,mid,high);
        Merge(v,low,mid,high); 
        return count; 
}

int main(){
    vector<int>v={40,25,19,12,9,6,2};
    int count = MergeSort(v,0,v.size()-1);
    cout<<count<<endl;
    return 0;
}

//time:O(2nlogn)
//space:O(n)