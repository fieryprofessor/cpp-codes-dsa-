//check if number is prime
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 41;
    bool flag = true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            flag = false;
            break;
        } 
    }
    if(flag)
    cout<<"Prime: true"<<endl;
    else
    cout<<"Prime: false"<<endl;
    
    return 0;
}
