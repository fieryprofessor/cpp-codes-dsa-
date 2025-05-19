//Sort the array of 0's , 1's and 2's. Dutch National Flag Algorithm
#include<bits/stdc++.h>
using namespace std;

void DNFSort(vector<int>&v){
   int low = 0 , mid = 0 , high= v.size()-1;
   while(mid<=high){
    if(v[mid]==0){
        swap(v[mid],v[low]);
        low++;
        mid++;
    }
    else if(v[mid]==1){
        mid++;
    }
    else{
        swap(v[mid],v[high]);
        high--;
        }
    }
}

int main(){
    vector<int>v = {0,1,2,0,1,2,1,2,0,0,0,1};
    DNFSort(v);
    for(int ele:v){
        cout<<ele<<" ";
    }
    return 0;
}

//time:O(n)
//space:O(1)