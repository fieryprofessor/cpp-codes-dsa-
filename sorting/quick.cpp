//Quick Sort - pick a pivot and place it in its correct position.
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&v,int low, int high){
    int pivot = v[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(v[j]<pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[high]);
    return i+1;
}

void QuickSort(vector<int>&v,int low , int high){
        if(low<high){
           int pos = partition(v,low,high);
           QuickSort(v,low,pos-1);
           QuickSort(v,pos+1,high);
        }    
}

int main(){
    vector<int>v={4,2,5,1,3};
    int n = v.size();
    QuickSort(v,0,n-1);
    for(int ele: v){
        cout<<ele<<" ";
    }
    return 0;
}

/*
 * Time Complexity = O(n^2), Θ(n.log(n))
 * Space Complexity = O(1)
 * Stable Sorting = No
 */