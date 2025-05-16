//find the intersection of two sorted arrays
#include<bits/stdc++.h>
using namespace std;

vector<int> intersectionSort(vector<int>&v1,vector<int>&v2){
    int i=0;
    int j=0;
    vector<int>v;
    while(i<v1.size()&& j<v2.size()){
        if(v1[i]<v2[j]){
            i++;
        }
        else if(v1[i]>v2[j]){
            j++;
        }
        else{
            v.push_back(v1[i]);
            i++;
            j++;
        }
    }
   
    return v;
}

int main(){
    vector<int>v1={1,2,4,8,67};
    vector<int>v2={4,7,8,54,67};
    vector<int>v = intersectionSort(v1,v2);

    for(int ele:v){
        cout<<ele<<" ";
    }
    return 0;
}

//time: O(n1+n2)
//space: O(n1+n2) only to print