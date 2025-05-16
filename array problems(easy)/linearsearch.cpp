//given a number ,return the first occurence of the number in the array
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={6,7,8,4,1};
    int n;
    cin>>n;

    int index =-1;

    for(int i=0;i<v.size();i++){
        if(v[i]==n){
            index = i;
        break;
        } 
    }
    
    cout<<index<<endl;
    return 0;
}

//time: O(n)
//space: O(1)