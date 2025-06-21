//Print all the prime factors of a number.
#include<bits/stdc++.h>
using namespace std;

vector<int> primeFactors(int n){
    vector<int>ans;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
            while(n%i==0)
            n=n/i;
        }
    }
    if(n!=1)  //edge case if n is a big prime number.
    ans.push_back(n); 
    return ans;
}

int main(){
    int n = 780;
    vector<int>ans = primeFactors(n);
    for(int ele : ans){
        cout<<ele<<" ";
    }
    return 0;
}

//time:O(root n)
//space:O(1)