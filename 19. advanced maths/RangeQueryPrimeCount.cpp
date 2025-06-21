//Given a query range L to R, Return the count of all prime numbers in this range.
#include<bits/stdc++.h>
using namespace std;

int MAXN = (int)1e6;
vector<int> prime(MAXN+1,1);
bool isSieveDone = false;

void Sieve(int n){
    prime[0]=prime[1]=0;
   for(long long i=2;i<=n;i++){
        if(prime[i]==1){
            for(long long j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
   }

   for (int i = 2; i <= n; i++) {
        prime[i] += prime[i-1];
    }
   
   isSieveDone = true;
}

int countPrimes(int l , int r){
    if (!isSieveDone) 
    Sieve(MAXN);
    return prime[r]-prime[l-1];
}

int main(){
    int l = 4;
    int r = 34;
    int count = countPrimes(l,r);
    cout<<count<<endl;
    return 0;
}

//time:O(n log log n)
//space:O(1e6)