// find the missing number in the array
#include<bits/stdc++.h>
using namespace std;

int missingNumberFinder(vector<int>&v,int n){
    int totalsum = (n*(n+1))/2;
    int sum=0;
    for(int ele:v){
        sum += ele;
    }
    return totalsum-sum;
}

int main(){
    int n = 5;
    vector<int> v ={1,2,4,5};
    
    int missingno = missingNumberFinder(v,n);
    cout<<missingno<<endl;

    return 0;
}

//time: O(n)
//space: O(1)