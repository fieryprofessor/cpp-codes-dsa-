//check if number is prime
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return b?gcd(b,a%b):a;
}

int main(){
    int a = 12, b = 8;
    int result = gcd(a,b);
    cout<<result<<endl;
    return 0;
}
