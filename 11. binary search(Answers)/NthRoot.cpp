//Find the nth root of a number.
#include<bits/stdc++.h>
using namespace std;

int BE(int a, int n){
    int ans=1;
    while(n>0){
        if(n&1)
        ans*=a;
        a*=a;
        n>>=1;
    }
    return ans;
}

int SquareRoot(int x,int n){
    int low=0;
    int high = n;
    int r=-1;
    while(low<=high){
        int mid = low+((high-low)/2);
        int check = BE(mid,x);
        if(check==n){
            r = mid;
            break;
        }
        else if(check>n)
        high=mid-1;
        else{
            r = mid;
            low=mid+1;
        }  
    }
    return r;
}

int main(){
    int answer = SquareRoot(3,64);
    cout<<answer<<endl;
    return 0;
}

//time:O(logn)
//space:O(1)