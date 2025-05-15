//Insertion Sort - Takes an element and places it in its correct position
#include<bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int>&v){
    int n = v.size();
    for(int i=0;i<n;i++){
       int j=i;
       while(j>0 && v[j-1]>v[j]){
        swap(v[j-1],v[j]);
        j--;
       }
    }
}

int main(){
    vector<int>v={4,2,5,1,3};
    InsertionSort(v);
    for(int ele: v){
        cout<<ele<<" ";
    }
    return 0;
}

/*Time Complexity = O(n^2)
 * Space Complexity = O(1)
 * Stable Sorting = Yes
 */