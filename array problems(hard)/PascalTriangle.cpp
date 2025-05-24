//Pascal Triangle
#include<bits/stdc++.h>
using namespace std;

int element(int n, int r){
    n--;r--;
    int res = 1;
    for(int i=0;i<r;i++){
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}

void generateRow(int n){
    int element=1;
    cout<<element<<" ";
    for(int i=1;i<n;i++){
       element*=(n-i);
       element/=i;
       cout<<element<<" ";
    }
}

int main(){
    //to print the element only
    cout<<element(5,3)<<endl;
     // time:O(r) space:O(1)

    //to print the nth row;
    int n=5;
    generateRow(n);
    cout<<endl;
    //time:O(n) space:O(1)

    //to print the triangle upto nth row
    for(int i=1;i<=n;i++){
        generateRow(i);
        cout<<endl;
    }
    //time:O(n^2) space:O(1)
    return 0;
}