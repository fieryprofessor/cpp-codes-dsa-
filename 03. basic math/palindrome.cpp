// check whether the number is palindrome or not.
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 121;
    int original = n;
    int rev = 0;
    while(n>0){
        int d = n%10;
        rev = (rev * 10)+d;
        n/=10;
    }
    if (rev==original)
    cout<<"Palindrome: true"<<endl;
    else
    cout<<"Palindrome: false"<<endl;
    return 0;
}