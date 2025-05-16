//remove the duplicates from the array and place the unique elements at the start.
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={1,1,2,2,2,3,3};
    int p = 0;
    for(int i=1;i<v.size();i++){
        if(v[i]!=v[p]){
            p++;
            swap(v[p],v[i]);   
        }
    }
     cout<<p+1<<endl;
    return 0;
}
//time: O(n)
//space: O(1)

//brute force
/*int main(){
    vector<int>v={1,1,2,2,2,3,3};
    set<int>s;
    for(int i=1;i<v.size();i++){
       s.insert(v[i]);
    }
    
    int index = 0;
    for(auto it: s){
        v[index]=it;
        index++;
    }
    cout<<index<<endl;
    return 0;
} */

//time: O(nlogn+n)
//space: O(n)