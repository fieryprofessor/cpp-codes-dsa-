// Binary Exponentiation - Calculating a^n in O(log n)
#include<bits/stdc++.h>
using namespace std;

int BE(int &a, int &n){
    int ans=1;
    while(n>0){
        if(n&1)
        ans*=a;
        a*=a;
        n>>=1;
    }
    return ans;
}

int main(){
    int a,n;
    cin>>a>>n;
    cout<<BE(a,n);
    return 0;
}