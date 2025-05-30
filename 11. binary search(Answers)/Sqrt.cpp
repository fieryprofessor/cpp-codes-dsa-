//find the square root of a number.
#include<bits/stdc++.h>
using namespace std;

int SquareRoot(int n){
    int low=0;
    int high = n;
    int sqr=-1;
    while(low<=high){
        int mid = low+((high-low)/2);
        if(mid==n/mid){
            sqr =mid;
            break;
        }
        else if(mid>n/mid)
        high=mid-1;
        else{
            sqr = mid;
            low=mid+1;
        }  
    }
    return sqr;
}

int main(){
    int answer = SquareRoot(49);
    cout<<answer<<endl;
    return 0;
}

//time:O(logn)
//space:O(1)
