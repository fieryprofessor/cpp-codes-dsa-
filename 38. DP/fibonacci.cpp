#include<bits/stdc++.h>
using namespace std;

//Memoization
int fibo(int n, vector<int>&dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = fibo(n-1,dp)+fibo(n-2,dp);
}
//time: O(n)
//space: O(n)+O(n)

//Tabulation
int fibo2(int n, vector<int>&dp){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//time:O(n)
//space:O(n)

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    int ans = fibo2(n,dp);
    cout<<ans<<endl;
    return 0;
}