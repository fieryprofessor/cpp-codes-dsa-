//move zeroes to the end of the array
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={1,0,2,3,2,0,0,4,5,1};

    int j=-1;
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1){
        cout<<"No zeroes in array"<<endl;
        return 0;
    }

    for(int i=j+1;i<v.size();i++){
        if(v[i]!=0){
            swap(v[j],v[i]);
            j++;
        }
    }
    
    for(int ele:v){
        cout<<ele<<" ";
    }
    return 0;
}

//time: O(n)
//space: O(1)