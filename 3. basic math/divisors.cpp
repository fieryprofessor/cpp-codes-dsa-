//print all divisors of a number
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 36;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
            if(n/i!=i)
            cout<<n/i<<" ";
        }
    }
    return 0;
}