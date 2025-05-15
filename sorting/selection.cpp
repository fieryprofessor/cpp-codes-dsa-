//Selection Sort - select minimum and swap it
#include<bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int>&v){
    int n = v.size();
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i;j<n;j++){
            if(v[j]<=v[min])
            min = j;
        }
        swap(v[min],v[i]);
    }
}

int main(){
    vector<int>v={4,2,5,1,3};
    SelectionSort(v);
    for(int ele: v){
        cout<<ele<<" ";
    }
    return 0;
}

/*
 * Time Complexity = O(n^2)
 * Space Complexity = O(1)
 * Stable Sorting = No
 */