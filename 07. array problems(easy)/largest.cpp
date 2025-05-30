//find the largest element in the array.
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={1,2,5,6,8,4};
    int largest = v[0];
    for(int ele:v){
        if(ele>=largest)
        largest = ele;
    }
    cout<<largest<<endl;
    return 0;
}

//time: O(n)