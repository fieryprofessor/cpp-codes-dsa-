//check if the number is armstrong
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 153;
    int original = n;
    int sum = 0;
    while(n>0){
        int d = n%10;
        sum+=d*d*d;
        n/=10;
    }
    if(sum==original)
    cout<<"Armstrong: true"<<endl;
    else
    cout<<"Armstrong: false"<<endl;
    return 0;
}