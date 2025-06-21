//given a number print the prime factorization of it.
#include<bits/stdc++.h>
using namespace std;

vector<int> primeFactorization(int n){
    vector<int>ans;
    vector<int>prime(n+1);
    for(int i=2;i<=n;i++){
        prime[i]=i;
    }

    for(int i=2;i*i<=n;i++){
        if(prime[i]==i){
            for(int j=i*i;j<=n;j+=i)
            prime[j]=i;
        }
    }

    while(n!=1){
        ans.push_back(prime[n]); 
        n /= prime[n];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n = 780;
    vector<int>ans = primeFactorization(n);
    for(int ele : ans){
        cout<<ele<<" ";
    }
    return 0;
}

//time:O(n log log n)
//space:O(n)