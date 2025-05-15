//Bubble Sort - push the max to the last by adjacent swapping
#include<bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int>&v){
    int n = v.size();
    for(int i=0;i<n-1;i++){
        bool flag = false;
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                flag = true;
            } 
        }
        if(!flag)
        break;
    }
}

int main(){
    vector<int>v={4,2,5,1,3};
    BubbleSort(v);
    for(int ele: v){
        cout<<ele<<" ";
    }
    return 0;
}

/*Time Complexity = O(n^2)
 * Space Complexity = O(1)
 * Stable Sorting = Yes
 */