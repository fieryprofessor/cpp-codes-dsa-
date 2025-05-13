//sort
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {4,2,5,1,3};
    sort(arr,arr+5);
    sort(arr,arr+5,greater<int>());
    return 0;
}