//find the second largest element in the array.
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={1,2,5,6,8,4};
    int largest = v[0];
    int secondl=-1;
    for(int ele:v){
        if(ele>=largest){
            secondl = largest;
            largest = ele;
        }
        else if(ele<largest && ele>=secondl){
            secondl = ele;
        }  
    }
    
    cout<<secondl<<endl;
    return 0;
}

//time: O(n)


/* brute force:
int main(){
    vector<int>v={1,2,5,6,8,4};
    int largest = v[0];
    for(int ele:v){
        if(ele>=largest)
        largest = ele;
    }
    int secondl = -1;
    for(int ele:v){
        if(ele>=secondl && ele!=largest)
        secondl = ele;
    }
    cout<<secondl<<endl;
    return 0;
}
time: O(2n)
    */