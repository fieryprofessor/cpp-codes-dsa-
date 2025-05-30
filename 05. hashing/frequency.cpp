//count the frequency of each number in the array
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[6];
    for(int i=0;i<6;i++){
        cin>>arr[i];
    }
    map<int,int> m;
    for(int ele:arr){
        m[ele]++;
    }

    for(auto it: m){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}