//Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n){
    double ans = 1.0;
    long long newn = n;
    if(newn<0)
    newn = -1 * newn;
    while(newn){
        if(newn%2==1){
            ans = ans*x;
            newn--;
        }else{
            x = x*x;
            newn /=2;
        }
    }
    if(n<0)
    ans = double(1.0)/(double)ans;
    return ans;
}

int main(){
    int x = 3;
    int n = 5;
    cout<<myPow(x,n)<<endl;
}

//time:O(log n)
//space:O(1)