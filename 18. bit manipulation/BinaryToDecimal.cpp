//Given a Binary string , convert it to its decimal equivalent number.
#include<bits/stdc++.h>
using namespace std;

int toDecimal(string s){
    int x = 0;
    for(char ch : s){
        int bit = ch - '0';  
        x = x * 2 + bit;     
    }
    return x;
}

int main(){
    string s = "1010";
    int num = toDecimal(s);
    cout<<num<<endl;
    return 0;
}

//time:O(n)  n = length of the string
//space:O(1)