//Given n find the xor of numbers from 1 to n, follow up xor of numers in a given range.
#include<bits/stdc++.h>
using namespace std;

int XorNumbers(int n){
    int ans = 0;
    if(n%4==1)
    ans = 1;
    else if(n%4==2)
    ans = n+1;
    else if(n%4==3)
    ans = 0;
    else
    ans = n;
    return ans;
}

int xorRange(int left, int right){
    int ans = XorNumbers(left-1)^XorNumbers(right);
    return ans;
}

int main(){
    int num = 7;
    int xorNum = XorNumbers(num);
    cout<<xorNum<<endl;
    int left = 4;
    int right = 7;
    int rangeXor = xorRange(left,right);
    cout<<rangeXor<<endl;
    return 0;
}

//time:O(1)
//space:O(1)