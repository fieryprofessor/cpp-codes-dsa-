//Convert the given decimal number to a binary string
#include<bits/stdc++.h>
using namespace std;

void reverse(string &s,int low , int high){
    while(low<=high){
        swap(s[low],s[high]);
        low++;
        high--;
    }
}

string toBinary(int x){
    string res = "";
    while(x>0){
        if(x%2==1)
        res += '1';
        else
        res += '0';
        x /= 2;
    }
    reverse(res,0,res.size()-1);
    return res;
}

int main(){
    int x = 10;
    string num = toBinary(x);
    cout<<num<<endl;
    return 0;
}

//time:O(logx)
//space:O(logx)