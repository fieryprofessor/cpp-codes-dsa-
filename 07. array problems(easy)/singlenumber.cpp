// find the number that appears only once and other numbers twice.
#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v ={1,1,2,3,3,4,4};
    int maximum = 0;
    int single = 0;
    for(int ele:v){
        single ^=ele;
    }
    cout<<single<<endl;
    
    return 0;
}

//time: O(n)
//space: O(1)