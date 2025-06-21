//Sieve Of Eratosthenes - Given a number n , print all the prime numbers upto n.
#include<bits/stdc++.h>
using namespace std;

vector<int> Sieve(int n){
    vector<int>ans;
    vector<int> prime(n+1,1);
   for(int i=2;i<=n;i++){
        if(prime[i]==1){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
   }
   for(int i=2;i<=n;i++){
    if(prime[i]==1)
    ans.push_back(i);
   }
   return ans;
}

int main(){
    int n = 50;
    vector<int>ans = Sieve(n);
    for(int ele : ans){
        cout<<ele<<" ";
    }
    return 0;
}

//time:O(n log log n)
//space:O(n)