//find the union of two sorted arrays
#include<bits/stdc++.h>
using namespace std;

vector<int> unionSort(vector<int>&v1,vector<int>&v2){
    int i=0;
    int j=0;
    vector<int>v;
    while(i<v1.size()&& j<v2.size()){
        if(v1[i]<=v2[j]){
            if(v.size()==0||v.back()!=v1[i]){
                v.push_back(v1[i]);
            }
            i++;
        }else{
            if(v.size()==0||v.back()!=v2[j]){
                v.push_back(v2[j]);
            }
            j++;
        } 
    }
    while(i<v1.size()){
        if(v.size()==0||v.back()!=v1[i]){
                v.push_back(v1[i]);
            }
            i++;
    }
    while(j<v2.size()){
       if(v.size()==0||v.back()!=v2[j]){
                v.push_back(v2[j]);
            }
            j++;
    }

    return v;
}

int main(){
    vector<int>v1={1,2,5,8,67};
    vector<int>v2={4,7,8,54,67};
    vector<int>v = unionSort(v1,v2);

    for(int ele:v){
        cout<<ele<<" ";
    }
    return 0;
}

//time: O(n1+n2)
//space: O(n1+n2) only to print