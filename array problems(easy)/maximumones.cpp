// find the maximum number of consecutive ones in the array.
#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v ={1,1,0,1,1,1,0,1,1};
    int maximum = 0;
    int count = 0;
    for(int i=0;i<v.size();i++){
        if(v[i]==1){
            count++;
            maximum=max(count,maximum);
        }else{
            count=0;
        }
    }
    cout<<maximum<<endl;
   
    return 0;
}

//time: O(n)
//space: O(1)