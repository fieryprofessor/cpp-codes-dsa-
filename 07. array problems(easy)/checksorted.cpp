//check if the array is sorted.
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={1,2,5,6,8,4};
    bool flag = true;
    for(int i=0;i<v.size()-1;i++){
        if(v[i]>v[i+1])
        flag = false;
    }
    if(flag)
    cout<<"Sorted:True"<<endl;
    else
    cout<<"Sorted:False"<<endl;
    return 0;
}

//time: O(n)